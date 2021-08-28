#include "datadb.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QTime>

////静态成员变量的类外初始化
//DataDB* DataDB::db = nullptr;

//DataDB::DataDB()
//{
//    //完成数据库的连接创建
//    //设置数据库的驱动
//    sqldb = QSqlDatabase::addDatabase("QMYSQL");
//    //配置数据库的基本信息
//    //设置数据库的名称
//    sqldb.setDatabaseName("userinfo");
//    //设置数据库的主机名（IP）如果是本地的localhost
//    sqldb.setHostName("localhost");
//    //设置用户名和密码
//    sqldb.setUserName("root");
//    sqldb.setPassword("4625130.wzx");
//    //设置端口号 本地数据库可以不用设置
//    sqldb.setPort(3306);

//    if(!sqldb.open()){
//        //提示
//        QMessageBox::warning(NULL,"error",
//                             "open db error!",
//                             QMessageBox::Yes);
//    }
//}

////
//struct User DataDB::selectAllUserOnline(QString name)
//{
//    //数据库操作类
//    //创建一个操作对象
//    QSqlQuery query;
//    //向数据库发送一个sql语句，让数据库执行
//    query.exec("select * from user where name = :name");
//    query.bindValue(":name",QVariant(name));
//    //查询结果存储query中，遍历该对象
//    struct User user;
//    while(query.next()){
//        //query.value("列名")
//        //query.value(索引值);
//        user.username = query.value("name").toString();
//        user.password = query.value("password").toString();
//    }

//    return user;
//}

////动态sql
//bool DataDB::selectUserByUnAndPwd(QString name,QString password)
//{
//    QSqlQuery query;
//    //向数据库发送一个预编译语句
//    query.prepare("select * from user where name =:name and password =:password");
//    //参数的绑定
//    query.bindValue(":name",QVariant(name));
//    query.bindValue(":password",QVariant(password));
//    //让数据库开始执行sql语句操作
//    query.exec();

//    bool flag;
//    if(query.next())
//        flag = true;
//    else
//        flag = false;

//    return flag;
//}

////注册的插入操作
//QString DataDB:: insertUser(struct User user)
//{
//    QSqlQuery query;

//    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
//    int id = qrand() % (99999 - 10000) + 10000;
//    QString id_1 = QString::number(id);

//    query.prepare("insert into user(name,password,id) values(:name,:password,:id)");
//    query.bindValue(":name",QVariant(user.username));
//    query.bindValue(":password",QVariant(user.password));
//    query.bindValue(":id",QVariant(id_1));

//    bool flag = query.exec();
//    if(!flag)
//    {
//        qDebug()<<QObject::tr ("插入失败\n");
//    }
//    else
//    {
//        qDebug()<<QObject::tr ("插入成功\n");
//    }
//    return id_1;
//}

////成为好友操作
//bool DataDB::insertFriend(QString id_1, QString id_2)
//{
//    QSqlQuery query;
//    QString name_1,name_2;

//    name_1 = selectNameByID(id_1);
//    name_2 = selectNameByID(id_2);
//    query.prepare("insert into friend(id_1,id_2,name_1,name_2)values(:id_1,:id_2,:name_1,:name_2);");
//    query.bindValue(":id_1",QVariant(id_1));
//    query.bindValue(":id_2",QVariant(id_2));
//    query.bindValue(":name_1",QVariant(name_1));
//    query.bindValue(":name_2",QVariant(name_2));

//    bool flag = query.exec();
//    if(!flag)
//    {
//        qDebug()<<QObject::tr ("添加失败\n");
//    }
//    else
//    {
//        qDebug()<<QObject::tr ("添加成功\n");
//    }
//    return flag;
//}

////好友查询操作
//QList <QString> DataDB:: selectFriend(QString id)
//{
//    QSqlQuery query;
//    query.prepare("select * from friend where id_1 =:id");
//    query.bindValue(":id",QVariant(id));
//    query.exec();

//    QList <QString> id_namelist;
//    while(query.next())
//    {
//        id_namelist << (query.value("id_2").toString() + "/" + query.value("name_2").toString());
//    }

//    query.prepare("select * from friend where id_2 =:id");
//    query.bindValue(":id",QVariant(id));
//    query.exec();

//    while(query.next())
//    {
//        id_namelist << (query.value("id_1").toString() + "/" + query.value("name_1").toString());
//    }
//    for(int i=0;i<id_namelist.size();i++){
//            qDebug()<<id_namelist.at(i);
//        }
//    return id_namelist;
//}

//QString DataDB::selectNameByID(QString id)
//{
//    QSqlQuery query;
//    query.prepare("select * from user where id =:id");
//    query.bindValue(":id",QVariant(id));

//    QString name = "false";
//    if(query.next()){
//        name = query.value("name").toString();
//    }
//    else{
//        qDebug() << "不存在该用户";
//    }
//    return name;
//}


//////查询用户名是否重复
////bool DataDB:: fingByName(QString name)
////{
////    QSqlQuery query;
////    query.prepare("select * from userinfo where name =:name");
////    query.bindValue(":name",QVariant(name));
////    query.exec();
////    bool flag;
////    if(query.next()){
////        flag = false;
////    }
////    else {
////        flag = true;
////    }
////    return flag;
////}

//DataDB* DataDB::getInstance()
//{
//    return (db == nullptr) ? (db = new DataDB) : db;
//}

