# dup-dup2
dup/dup2编程练习
系统调用dup和dup2能够复制文件描述符。
dup返回新的文件文件描述符（没有用的文件描述符最小的编号）。
 eg：重定向标准输出到一个文件。
 close（1）;//先要关闭1号文件描述符。
 int new_fd = dup（fd）；
dup2可以让用户指定返回的文件描述符的值，如果需要，则首先关闭newfd的值，他通常用来重新打开或者重定向一个文件描述符。
他的原型如下：
#include <unsitd.h>
int dup(int oldfd);
int dup2(int oldfd,int newfd);
dup 和dup2都是返回新的描述符。或者返回-1并设置errno变量。新老描述符共享文件的偏移量（位置）、标志和锁，但是不共享close-on-exec标志。
