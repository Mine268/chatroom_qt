#ifndef DATADB_H
#define DATADB_H
#include <QSqlDatabase>

/*
 * commnet by mine268 at 2021-8-28
 * 1. 使用nullptr作为空指针而不是null
 * 2. 数据库连接不要做在构造函数的时候，给出配置数据库基本信息
 *    的接口，并提供连接数据库的启动方法
 * 3. 数据库断开，析构函数
 * 4. 两个struct请作为DataDB的内部成员声明并定义
 * 5. 使用引用传递参数可以提高效率
*/

class DataDB {
public:
    // 存储用户信息的结构体
    struct userInfo {
        qint64      id;
        QString		name;
        QString		email;
    };
    // 存储消息信息的结构体
    struct msgInfo {
        qint64      from;
        qint64      to;
        QString		time;
        QString		msg;
    };

    // 数据库配置
    void configure(const QString &_driver = "QMYSQL"	  // 数据库驱动
                 , const QString &_dbName = "userinfo"        // 数据库名称
                 , const QString &_host = "localhost"		  // 设置数据库主机地址
                 , const short 	 &_port = 3306                // 设置数据库主机端口
                 , const QString &_name = "root"              // 设置数据库登录名称
                 , const QString &_pwd = "4625130.wzx"		  // 设置数据库登录密码
                 );

    // 连接到数据库，返回值指示是否连接成功
    bool connectToDB();

    // 查询是否存在此人，按照id查询，返回个人信息在info中
    // 返回值指示是否查询成功
    bool findUser(qint64 id, userInfo &info);
    // 分别指代用户id和密码
    bool loginVerify(const qint64 _id, const QString &_pwd);
    // 分别指代注册的用户名和密码，返回id
    QString registerQuest(const QString &_user, const QString &_pwd);
    // 存储消息（在接收方不在线的时候调用），返回值指示是否存储成功
    bool saveMessage(const qint64 _from, const qint64 _to
                    , const QString &_time, const QString &_msg);
    // 读取某人的未读消息
    QList<msgInfo> readMessage(const qint64 _to);
    // 添加好友，返回值指示是否添加成功
    bool friendAdd(qint64 id1, qint64 id2);
    // 删除好友，返回值指示是否删除成功
    bool friendDel(qint64 id1, qint64 id2);
    // 返回某个人的所有好友
    QList<userInfo> friendList(qint64 id);

    // 析构函数用于释放空间等等操作
    //~DataDB();

    static DataDB *getInstance();
    static DataDB *releaseInstance();
private:

    // 释放单例（断开连接等等）
    static DataDB	*db;
    // 对数据库时间格式进行修正的函数
    static inline QString timeTrim(const QString&);

    QSqlDatabase sqldb;
    explicit DataDB();
    ~DataDB();
};

#endif // DATADB_H
