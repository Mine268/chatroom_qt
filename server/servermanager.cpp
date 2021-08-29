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
    auto regResult = db->registerQuest(_name, _pwd);
    if (regResult != "")
        tcpserver->sendRegConfirm(_skt, regResult);
    else
        tcpserver->sendRegDeny(_skt, "注册失败。");
}

void ServerManager::getMessage(const QString &_from, const QString &_to
                               , const QString &_date, const QString &_msg)
{
    if (loginUsers.find(_to.toLongLong()) == loginUsers.end()) {
        // 此人不在线
        db->saveMessage(_from.toLongLong(), _to.toLongLong(), _date, _msg);
    } else {
        // 此人在线
        tcpserver->sendChatMsg(loginUsers[_from.toLongLong()]
                , _from, _to, _date, _msg);
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
        tcpserver->sendChatImg(loginUsers[_from.toLongLong()]
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
    if(db->findUser(query_id,user_info)){
        QString name = user_info.name;
        QString email = user_info.email;
        tcpserver->sendUserInfo(loginUsers[query_id],name,email);
    } else {
        tcpserver->sendUserInfo(loginUsers[query_id],"null","null");
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
}

void ServerManager::getPullHangedMsg(const qint64 _id)
{
    auto list = db->readMessage(_id);
    for (auto iter = list.begin(); iter != list.end(); ++iter)
        tcpserver->sendChatMsg(loginUsers[_id]
                               , QString::number(iter->from)
                               , QString::number(iter->to)
                               , iter->date
                               , iter->msg);
}

void ServerManager::getUserDropEx(QTcpSocket *_skt)
{
    // 处理异常掉线
    auto id = r_loginUsers[_skt];
    auto iter1 = loginUsers.find(id);
    auto iter2 = r_loginUsers.find(_skt);

    loginUsers.erase(iter1);
    r_loginUsers.erase(iter2);

    qDebug() << "[info]" << id << "dropped.";
}


