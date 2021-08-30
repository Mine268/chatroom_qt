#include "servermanager.h"
#include <QDataStream>

ServerManager::ServerManager(QObject *parent) : QObject(parent)
{
    tcpserver = nullptr;
    db = nullptr;
}

ServerManager::~ServerManager()
{
    TcpServer::releaseInstance();
    // 等db写好就可以用了
    DataDB::releaseInstance();
}

void ServerManager::configure(QHostAddress _serverHost
                              , short _serverPort
                              , const QString &_dbDriver
                              , const QString &_dbName
                              , const QString &_dbHost
                              , const short &_dbPort
                              , const QString &_dbUsr
                              , const QString &_dbPwd)
{
    serverHost  =   _serverHost;
    serverPort  =   _serverPort;
    dbDriver    =   _dbDriver;
    dbName      =   _dbName;
    dbHost      =   _dbHost;
    dbPort      =   _dbPort;
    dbUsr       =   _dbUsr;
    dbPwd       =   _dbPwd;
}

void ServerManager::start()
{
    // TODO: 等db写好就可以用了
    db = DataDB::getInstance();
    db->configure(dbDriver, dbName, dbHost, dbPort, dbUsr, dbPwd);
    db->connectToDB();

    tcpserver = TcpServer::getInstance();
    tcpserver->configure(serverHost, serverPort);
    tcpserver->start();

    connect(tcpserver, &TcpServer::recvLogin, this, &ServerManager::getLogin);
    connect(tcpserver, &TcpServer::recvRegister, this, &ServerManager::getRegister);
    connect(tcpserver, &TcpServer::recvMessage, this, &ServerManager::getMessage);
    connect(tcpserver, &TcpServer::recvFriendAddQuest, this, &ServerManager::getFriendAddQuest);
    connect(tcpserver, &TcpServer::recvFriendDelQuest, this, &ServerManager::getFriendDelQuest);
    connect(tcpserver, &TcpServer::recvFriendListQuest, this, &ServerManager::getFriendListQuest);
    connect(tcpserver, &TcpServer::usrDisconnectedEx, this, &ServerManager::getUserDropEx);
    connect(tcpserver, &TcpServer::recvImage, this, &ServerManager::getImage);
    connect(tcpserver, &TcpServer::recvUserQuery, this, &ServerManager::getUserQueryQuest);
    connect(tcpserver, &TcpServer::recvPullHangedMsg, this, &ServerManager::getPullHangedMsg);
}

void ServerManager::sendHangedMsg(const qint64 _id)
{
    auto msgList = db->readMessage(_id);
    tcpserver->sendChatMsg(loginUsers[_id], msgList);
}

void ServerManager::getLogin(QTcpSocket *_skt, const QString &_usr, const QString &_pwd)
{
    auto id = _usr.toLongLong();
    auto valid = db->loginVerify(id, _pwd);
    auto logined = (loginUsers.find(id) == loginUsers.end());

    if (!valid) {
        // 查无此人
        tcpserver->sendLoginDeny(_skt, "请检查用户id和密码。");
    } else if (!logined) {
        // 此人已登录
        tcpserver->sendLoginDeny(_skt, "您已登录。");
    } else {
        // 准许登录
        tcpserver->sendLoginConfirm(_skt);
        loginUsers[id] = _skt;
        r_loginUsers[_skt] = id;
    }
}

void ServerManager::getRegister(QTcpSocket *_skt
                                , const QString &_name, const QString &_pwd)
{
    qDebug() << "[srm registerQuest]:" << _name << _pwd;
    auto regResult = db->registerQuest(_name, _pwd);
    if (regResult != "") {
        tcpserver->sendRegConfirm(_skt, regResult);
        ;
    } else
        tcpserver->sendRegDeny(_skt, "注册失败。");
}

void ServerManager::getMessage(const QString &_from, const QString &_to
                               , const QString &_date, const QString &_msg)
{
    qDebug() << "[srm getMsg]:" << _from << _to << _date << _msg;
    if (loginUsers.find(_to.toLongLong()) == loginUsers.end()) {
        // 此人不在线
        db->saveMessage(_from.toLongLong(), _to.toLongLong(), _date, _msg);
    } else {
        // 此人在线
        tcpserver->sendChatMsg(loginUsers[_to.toLongLong()]
                , {{_from.toLongLong(), _to.toLongLong(), _date, _msg}});
    }
}

void ServerManager::getImage(const QString &_from, const QString &_to
                             , const QString &_date, const QString& _image)
{
    if (loginUsers.find(_to.toLongLong()) == loginUsers.end()) {
        // 此人不在线
        //db->imageSave(_from.toLongLong(), _to.toLongLong(), _date, _msg);
    } else {
        // 此人在线
        tcpserver->sendChatImg(loginUsers[_to.toLongLong()]
                , _from, _to, _date, _image);
    }


}

QImage ServerManager::StringToQImage(const QString & rawData)
{
    QByteArray imageData = QByteArray::fromBase64(rawData.toLatin1());
    QImage image;
    image.loadFromData(imageData);
    return image;
}

void ServerManager::getUserQueryQuest(const qint64 query_id,const qint64 sender_id)
{
    struct DataDB::userInfo user_info;
    if(db->findUser(query_id, user_info)){
        QString name = user_info.name;
        QString email = user_info.email;
        qDebug() << "[srm getUserQueryQuest]:" << name << email;
        qDebug() << "[srm getUserQueryQuest][sender_id]:" << sender_id;
        tcpserver->sendUserInfo(loginUsers[sender_id], query_id, name, email);
    } else {
        tcpserver->sendUserInfo(loginUsers[sender_id], -1, "", "");
    }

}

void ServerManager::getFriendAddQuest(const QString &_me, const QString &_you)
{
    auto _id1 = _me.toLongLong();
    auto _id2 = _you.toLongLong();

    db->friendAdd(_id1, _id2);
}

void ServerManager::getFriendDelQuest(const QString &_me, const QString &_you)
{
    auto _id1 = _me.toLongLong();
    auto _id2 = _you.toLongLong();

    db->friendDel(_id1, _id2);
}

void ServerManager::getFriendListQuest(const QString &_id)
{
    auto id = _id.toLongLong();
    auto list = db->friendList(id);
    QList<std::tuple<QString, QString, bool>> res;

    for (auto iter = list.begin(); iter < list.end(); ++iter) {
        res.append(std::tuple<QString, QString, bool>
                   (QString::number(iter->id), iter->name
                    , loginUsers.find(iter->id) != loginUsers.end()));
    }
    // id, name, online
    tcpserver->sendFriendList(loginUsers[id], res);

    // 登录后发送未读消息
    sendHangedMsg(id);
}

void ServerManager::getPullHangedMsg(const qint64 _id)
{
    sendHangedMsg(_id);
}

void ServerManager::getUserDropEx(QTcpSocket *_skt)
{
    // 处理异常掉线
    auto id = r_loginUsers[_skt];
    auto iter1 = loginUsers.find(id);
    auto iter2 = r_loginUsers.find(_skt);

    loginUsers.erase(iter1);
    r_loginUsers.erase(iter2);

    _skt->close();

    qDebug() << "[info]" << id << "dropped.";
}


