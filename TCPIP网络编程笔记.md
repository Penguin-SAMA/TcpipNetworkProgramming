# 第一章 理解编程和套接字

## 1.1 理解编程和套接字

### 1.1.1 网络编程和套接字概要

套接字是网络数据传输用的软件设备。

编程中的“套接字”就是用来连接该网络的工具。

### 1.1.2 构建电话套接字

#### 调用 socket 函数时进行的对话

```c
#include <sys/socket.h>

int socket(int domian, int type, int protocol);
//成功时返回文件描述符，失败时返回-1
```

#### 调用 bind 函数时进行的对话

```c
#include <syd/socket.h>

int bind(int sockfd, struct sockaddr *myaddr, socklen_t addrlen);
//成功时返回0，失败时返回-1
```

#### 调用 listen 函数时进行的对话

```c
#include <sys/socket.h>

int listen(int sockfd, int backlog);
//成功时返回0，失败时返回-1
```

#### 调用 accept 函数时进行的对话

```c
#include <sys/socket.h>

int accpet(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
//成功时返回文件描述符，失败时返回-1
```

网络编程中接受连接请求的套接字创建过程如下:

- 调用 socket 函数创建套接字
- 调用 bind 函数分配 IP 地址和端口号
- 调用 listen 函数转为可接受请求状态
- 调用 accept 函数转为可接受请求状态
