#include "datadb.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QTime>

//静态成员变量的类外初始化
DataDB* DataDB::db = nullptr;

DataDB::DataDB()
{}

// 数据库配置
void DataDB::configure(const QString &_driver	  // 数据库驱动
             , const QString &_dbName             // 数据库名称
             , const QString &_host		          // 设置数据库主机地址
             , const short 	 &_port               // 设置数据库主机端口
             , const QString &_name               // 设置数据库登录名称
             , const QString &_pwd                // 设置数据库登录密码
             )
{
    //设置数据库的驱动
    sqldb = QSqlDatabase::addDatabase(_driver);
    //配置数据库的基本信息
    //设置数据库的名称
    sqldb.setDatabaseName(_dbName);
    //设置数据库的主机名（IP）如果是本地的localhost
    sqldb.setHostName(_host);
    //设置用户名和密码
    sqldb.setUserName(_name);
    sqldb.setPassword(_pwd);
    //设置端口号 本地数据库可以不用设置
    sqldb.setPort(_port);
}

// 连接到数据库，返回值指示是否连接成功
bool DataDB::connectToDB()
{
    if(!sqldb.open()){
        return true;
    }
    else{
        return false;
    }
}

// 查询是否存在此人，按照id查询，返回个人信息在info中
// 返回值指示是否查询成功
bool DataDB::findUser(qint64 id, userInfo &info)
{
    QSqlQuery query;
    query.prepare("select * from users where id =:id");
    query.bindValue(":id",QVariant(id));
    query.exec();

    QString name = "false";
    if(query.next()){
        info.id = query.value("id").toInt();
        info.name = query.value("name").toString();
        info.email = query.value("email").toString();
        qDebug() << "查询用户成功";
        return true;
    }
    else{
        qDebug() << "不存在该用户";
        return false;
    }
}

// 分别指代用户id和密码
bool DataDB::loginVerify(const qint64 _id, const QString &_pwd)
{
    QSqlQuery query;
    query.prepare("select * from users where id =:id and password =:password");
    query.bindValue(":id",QVariant(_id));
    query.bindValue(":password",QVariant(_pwd));
    query.exec();
    if(query.next())
        return true;
    else
        return false;
}

// 分别指代注册的用户名和密码，返回id
QString DataDB::registerQuest(const QString &_user, const QString &_pwd)
{
    QSqlQuery query;

    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    int id = qrand() % (99999 - 10000) + 10000;
    QString id_1 = QString::number(id);

    query.prepare("insert into users(name,password,id) values(:name,:password,:id)");
    query.bindValue(":name",QVariant(_user));
    query.bindValue(":password",QVariant(_pwd));
    query.bindValue(":id",QVariant(id_1.toInt()));

    bool flag = query.exec();
    if(!flag)
    {
        qDebug()<<QObject::tr ("注册失败\n");
    }
    else
    {
        qDebug()<<QObject::tr ("注册成功\n");
    }
    return id_1;
}

// 存储消息（在接收方不在线的时候调用），返回值指示是否存储成功
bool DataDB::messageSave(const qint64 _from, const qint64 _to
                , const QString &_time, const QString &_msg)
{
    QSqlQuery query;
    query.prepare("insert into unread-message(src,dest,time,msg) values(:id,:from,:to,:time,:msg)");
    query.bindValue(":from",QVariant(_from));
    query.bindValue(":to",QVariant(_to));
    query.bindValue(":msg",QVariant(_time));
    query.bindValue(":msg",QVariant(_msg));

    bool flag = query.exec();
    if(!flag)
    {
        qDebug()<<QObject::tr ("存储消息失败\n");
    }
    else
    {
        qDebug()<<QObject::tr ("存储消息成功\n");
    }
    return flag;
}

// 添加好友，返回值指示是否添加成功
bool DataDB::friendAdd(qint64 id1, qint64 id2)
{
    QSqlQuery query;
    query.prepare("insert into friend-relation(partner1,partner2)values(:id1,:id2)");
    query.bindValue(":id_1",QVariant(id1));
    query.bindValue(":id_2",QVariant(id2));

    bool flag = query.exec();
    if(!flag)
    {
        qDebug()<<QObject::tr ("添加好友失败\n");
    }
    else
    {
        qDebug()<<QObject::tr ("添加好友成功\n");
    }
    return flag;
}

// 删除好友，返回值指示是否删除成功
bool DataDB::friendDel(qint64 id1, qint64 id2)
{
    QSqlQuery query;
    query.prepare("DELETE FROM friend-relation WHERE partner1 = :id1 and partner2 = :id2");
    query.bindValue(":id1",QVariant(id1));
    query.bindValue(":id2",QVariant(id2));

    bool flag = query.exec();
    if(!flag)
    {
        qDebug()<<QObject::tr ("删除好友失败\n");
    }
    else
    {
        qDebug()<<QObject::tr ("删除好友成功\n");
    }
    return flag;
}

// 返回某个人的所有好友
QList <DataDB:: userInfo> DataDB:: friendList(qint64 id)
{
    QSqlQuery query;
    query.prepare("select * from friend-relation where partner1 =:id");
    query.bindValue(":id",QVariant(id));
    query.exec();

    QList <qint64> idlist;
    QList <userInfo> friendlist;
    struct userInfo info;

    while(query.next())
    {
        idlist << query.value("partner2").toInt();
    }

    query.prepare("select * from friend-relation where partner2 =:id");
    query.bindValue(":id",QVariant(id));
    query.exec();

    while(query.next())
    {
        idlist << query.value("partner1").toInt();
    }

    for(int i=0;i<idlist.size();i++){
        findUser(idlist.at(i), info);
        friendlist << info;
        qDebug()<<info.name;
    }
    return friendlist;
}

DataDB* DataDB::getInstance()
{
    if(db == nullptr){
        db = new DataDB;
    }
    return db;
}

//DataDB* DataDB::releaseInstance()
//{
//    if(db != nullptr)
//        delete db;
//}
