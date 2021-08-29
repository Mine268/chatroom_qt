# 通信格式

format 1.3

```
相对于 format 1.0 添加了属于client发送的friend[Add|Del]Quest的quest和对应的value含义
```

在服务器和客户端之间通信应当遵循如下的格式和说明。

## 通信分类

按照发送方分类，通信可以划分为来自客户端的通信和来自服务端的通信。

### 来自客户端的通信

1. 发送登陆信息
2. 发送注册信息
3. 要发送给其他客户的信息
4. 发送请求好友列表消息
5. 发送给其他用户的图片信息

### 来自服务端的通信

1. 发送登陆确认信息
2. 发送注册确认信息
3. 发送好友列表信息
4. 转发的聊天信息
5. 转发的图片信息

## 通信语法

通信语法遵循 `JSON` 语法。

```json
{
    "sender":"server", // 发送方，可选值为 server 和 client，分别代表服务器和客户端
    "quest":"loginConfirm", // 发送方（sender）希望进行的操作
    /*
    如果发送方为server，那么quest分别有
    	- loginConfirm 登陆确认，如果用户登陆成功则返回这个
    	- loginDeny 登录否认，用户无法登录
    	- registerConfirm 注册确认，如果用户注册成功则返回这个
    	- registerDeny 注册否认，如果用户注册失败则返回这个
    	- friendList 发送好友列表
    	- messageTransmit 转发的聊天信息
        - imageTransmit 转发的图片消息
    //  - friendAccept 同意添加好友
    如果发送方为client，那么quest分别由
    	- loginQuest 登录请求
    	- registerQuest 注册请求
    	- messageSend 发送消息请求
    	- friendAddQuest 添加好友请求
    	- friendDelQuest 删除好友请求
    	- friendList 好友列表请求
        - imageSend 发送图片请求
    */
    "value":"" // 这里是每个quest的具体内容
}
```

当 `quest` 为 `loginConfirm` 时，`value` 为字符串 `true`。

当 `quest` 为 `loginDeny` 时，`value` 为字符串，包含登陆失败的原因。

当 `quest` 为 `registerConfirm` 时，`value` 为 `json` 对象

```json
{
    "id":"114514";
}
```

当 `quest` 为 `registerDeny` 时，`value` 为字符串，包含注册失败的原因。

当 `quest` 为 `friendList` 时，`value` 为数组

```json
[
    {"id":"114515","name":"1919810","online":"true"}, // 每个对象分别是好友的id和名字
    {"id":"7355608","name":"Bank","online": "false"}
]
```

当 `quest` 为 `messageTransmit` 时，`value` 为 `json` 对象

```json
{
    "from":"114515", // 谁发的消息
    "to":"7355608", // 谁接受消息
    "time":"2021-10-1 14:44", // 消息的发送时间
    "value":"hello" // 消息内容
}
```

当 `quest` 为 `loginQuest` 时，`value` 为 `json` 对象

```json
{
    "usrname":"114514", // 登录用户id
    "password":"dkasjfosiajfoipajfiorjgingjsihgfiuor" // 密码
}
```

当 `quest` 为 `registerQuest` 时，`value` 为 `json` 对象

```json
{
    "usrname":"114514", // 注册用户id
    "password":"dkasjfosiajfoipajfiorjgingjsihgfiuor" // 密码
}
```

当 `quest` 为 `messageSend` 时，`value` 为 `json` 对象

```json
{
    "from":"114515", // 谁发的消息
    "to":"7355608", // 谁接受消息
    "time":"2021-10-1 14:44", // 消息的发送时间
    "value":"hello" // 消息内容
}
```

当 `quest` 为 `friendAddQuest` 时，`value` 为 `json` 对象

```json
{
    "me":"119293", // 谁要加
   	"you":"339923" // 加谁
}
```

当 `quest` 为 `friendDelQuest` 时，`value` 为 `json` 对象

```json
{
    "me":"119293", // 谁要删
   	"you":"339923" // 删谁
}
```

当`quest`为`friendList`时，`value`为`json`对象

```json
{
    "id":"222222" // 需要获取的那个人的好友列表
}
```

当`quest`为`image`时， `value`为`json`对象
```json
{
    "from":"114515", // 谁发的消息
    "to":"7355608", // 谁接受消息
    "time":"2021-10-1 14:44", // 消息的发送时间
    "value":"DNDGJ0DKJFHDSKJFH65465465........" // QByteArray形式存储的base64格式的图片串  ***注意签名为QByteArray！
} 
```



