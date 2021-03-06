# 通信格式

format 1.4.1

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
6. 发送添加好友请求

### 来自服务端的通信

1. 发送登陆确认信息
2. 发送注册确认信息
3. 发送好友列表信息
4. 转发的聊天信息
5. 转发的图片信息
6. 发送添加好友请求

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
    	- returnUserInfo 返回用户信息
    如果发送方为client，那么quest分别由
    	- loginQuest 登录请求
    	- registerQuest 注册请求
    	- messageSend 发送消息请求
    	- searchUserByID 发送搜索好友
    	- friendAddQuest 添加好友请求
    	- friendDelQuest 删除好友请求
    	- friendList 好友列表请求
        - imageSend 发送图片请求
    */
    "value":"" // 这里是每个quest的具体内容
}
```

如果发送方为server，那么quest分别有
 - loginConfirm 登陆确认，如果用户登陆成功则返回这个
- loginDeny 登录否认，用户无法登录
- registerConfirm 注册确认，如果用户注册成功则返回这个
- registerDeny 注册否认，如果用户注册失败则返回这个
- friendList 发送好友列表
- messageTransmit 转发的聊天信息
- returnUserInfo 返回用户信息
- 关于好友
  - friendAccept 同意添加好友
  - friendDeny 拒绝添加为好友
  - addFriendQuest 向用户确认是否允许添加为好友

如果发送方为client，那么quest分别由
 - loginQuest 登录请求
- registerQuest 注册请求
- messageSend 发送消息请求
- searchUserByID 发送搜索好友
- 关于好友
  - friendAddQuest 添加好友请求
  - friendAgree 同意添加好友
  - friendDisagree 拒绝添加好友
  - friendDelQuest 删除好友请求
- friendList 好友列表请求
- imageSend 发送图片请求
- pullHangedMessage 请求未读信息

### sender = server

当 `quest` 为 `loginConfirm` 时，`value` 为字符串 `true`。

当 `quest` 为 `loginDeny` 时，`value` 为字符串，包含登陆失败的原因。

当 `quest`为`addFriendQuset` ,`value`为`json`对象

```json
{
    "sender_id": "2222",
    "quest_id":"2222"
}
```

当 `quest`为`friendAccept` ,`value`为`json`对象

```json
{
    "id":"3333",//账号
    "name":"", // 名称
    "email":"" // 邮箱
}
```

当 `quest`为`friendDeny` ,`value`为字符串`false`

当 `quest` 为 `regiterConfirm` 时，`value` 为 `json` 对象

```json
{
    "id":"114514"
}
```

当 `quest` 为 `registerDeny` 时，`value` 为字符串，包含注册失败的原因。

当 `quest` 为 `returnUserInfo` 时，`value` 为字符串，

```json
{
    "name":"sdasd",
    "email":""
}
```

当 `quest` 为 `friendList` 时，`value` 为数组

```json
[
    {"id":"114515","name":"1919810","online":"true"}, // 每个对象分别是好友的id和名字
    {"id":"7355608","name":"Bank","online": "false"}
]
```

当 `quest` 为 `messageTransmit` 时，`value` 为 `json` 数组

```json
[
    {
        "from":"114515", // 谁发的消息
        "to":"7355608", // 谁接受消息
        "time":"2021-10-1 14:44", // 消息的发送时间
        "value":"hello" // 消息内容
    },
    {
        "from":"334324", // 谁发的消息
        "to":"7355608", // 谁接受消息
        "time":"2021-10-1 14:24", // 消息的发送时间
        "value":"hi" // 消息内容
    }
]
```

当 `quest` 为 `returnUserInfo` 时，`value` 为 `json` 对象

```json
{
    "id":"3333",//账号
    "name":"", // 名称
    "email":"" // 邮箱
}
```

### sender = client

当 `quest` 为 `loginQuest` 时，`value` 为 `json` 对象

```json
{
    "id":"114514", // 登录用户id
    "password":"dkasjfosiajfoipajfiorjgingjsihgfiuor" // 密码
}
```

当 `quest` 为 `registerQuest` 时，`value` 为 `json` 对象

```json
{
    "username":"114514", // 注册用户名称
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

当`quest`为 `searchUserByID`，`value` 为`json`对象

```json
{
    "query_id":"222222",
    "sender_id":"2222"
}
```

当 `quest` 为 `pullHangedMessage` 时，`value` 为字符串，内容为要读取未读消息的人的id。

当 `quest` 为 `friendAddQuest` 时，`value` 为`json`

```json
{
	"query_id":"222",
    "sender_id":"2222"
}
```

当 `quest` 为 `friendAgree` 时，`value` 为`json`

```json
{
	"id":"3333",//账号
    "name":"", // 名称
    "email":"" // 邮箱
}
```

当 `quest` 为 `friendDisagree` 时，`value` 为字符串`false`

