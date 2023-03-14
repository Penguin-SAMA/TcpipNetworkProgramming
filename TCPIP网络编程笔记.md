# 第一章 理解网络编程和套接字

## 1.1 理解网络编程和套接字

### 1.1.1 网络编程和套接字概要

套接字是网络数据传输用的软件设备。

编程中的“套接字”就是用来连接该网络的工具。

### 1.1.2 构建电话套接字

#### 调用socket函数时进行的对话

```c
#include <sys/socket.h>

int socket(int domian, int type, int protocol);
//成功时返回文件描述符，失败时返回-1
```

#### 调用bind函数时进行的对话

```c
#include <syd/socket.h>

int bind(int sockfd, struct sockaddr *myaddr, socklen_t addrlen);
//成功时返回0，失败时返回-1
```

#### 调用listen函数时进行的对话

```c
#include <sys/socket.h>

int listen(int sockfd, int backlog);
//成功时返回0，失败时返回-1
```

#### 调用accept函数时进行的对话

```c
#include <sys/socket.h>

int accpet(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
//成功时返回文件描述符，失败时返回-1
```

网络编程中接受连接请求的套接字创建过程如下:

- 调用socket函数创建套接字
- 调用bind函数分配IP地址和端口号
- 调用listen函数转为可接受请求状态
- 调用accept函数转为可接受请求状态

## 1.2 基于Linux的文件操作

对Linux而言，socket操作与文件操作没有区别。

在Linux世界里，socket也被认为是文件的一种，因此在网络数据传输过程中自然可以使用文件I/O的相关函数。

### 1.2.1 底层文件访问和文件描述符

"底层"：与标准无关的操作系统独立提供的。

如果想使用Linux提供的文件I/O函数，首先应该理解好文件描述符的概念。

文件和套接字一般经过创建过程才会被分配文件描述符。

### 1.2.2 打开文件

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//path			文件名的字符串信息
//flag			文件打开模式信息
int open(const char *path, int flag);
//成功时返回文件描述符，失败时返回-1
```

### 1.2.3 关闭文件

```c
#include <unistd.h>

//fd			需要关闭的文件或套接字的文件描述符
int close(int fd);
//成功时返回0，失败时返回-1
```

若调用此函数的同时传递文件描述符参数，则关闭相应文件。

此函数不仅可以关闭文件，还可以关闭套接字。

### 1.2.4 将数据写入文件

```c
#include <unistd.h>

//fd			显示数据传输对象的文件描述符
//buf			保存要传输数据的缓冲地址值
//nbytes		要传输数据的字节数
ssize_t write(int fd, const void * buf, size_t nbytes);
//成功时返回写入的字节数，失败时返回-1
```

其中`ssize_t`是通过typedef声明的`unsigned int`类型。

### 1.2.5 读取文件中的数据

```cpp
#include <unistd.h>

//fd			显示数据接收对象的文件描述符
//buf			要保存接收数据的缓冲地址值
//nbytes		要接受数据的最大字节数
ssize_t read(int fd, void *buf, size_t nbytes);
//成功时返回接收的字节数(如果遇到文件结尾返回0)，失败时返回-1
```

