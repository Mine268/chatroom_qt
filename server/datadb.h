#ifndef DATADB_H
#define DATADB_H
#include <QSqlDatabase>

struct User{
    //int id;
    QString username;
    QString password;
};

struct fried{
    QString name_1;
    QString name_2;
};

class DataDB
{
public:
    explicit DataDB();
    //单例设计模式——应对数据库的对象的内存使用
    static DataDB* getInstance();
    //登录功能的数据库操作——动态sql
    bool selectUserByUnAndPwd(QString name, QString password);
    //注册的插入操作
    QString insertUser(struct User user);
    //成为好友操作
    bool insertFriend(QString name_1, QString name_2);
    //好友查询操作
    QList <QString> selectFriend(QString name);

    //    //查询用户名是否重复
    //    bool fingByName(QString name);
    //查询当前全部用户的数据库操作——静态sql
    struct User selectAllUserOnline(QString name);

private:
    QSqlDatabase sqldb;
    static DataDB* db;
};

#endif // DATADB_H

