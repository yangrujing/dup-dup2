# dup-dup2
dup/dup2编程练习
他的原型如下：
##include <unsitd.h>
int dup(int oldfd);
int dup2(int oldfd,int newfd);
系统调用dup和dup2能够复制文件描述符。
dup返回新的文件文件描述符（文件描述符表中最小的未被使用的文件描述符）。
 eg：重定向标准输出到一个文件。
 close（1）;//先要关闭1号文件描述符。
 int new_fd = dup（fd）；
dup2可以让用户指定返回的文件描述符的值，如果newfd已将打开，先将其关闭，他通常用来重新打开或者重定向一个文件描述符。
如果newfd=oldfd，则不关闭newfd，直接返回newfd。
dup 和dup2都是成功返回新的描述符。失败返回-1并设置errno变量。新老描述符共享文件的偏移量（位置）、标志和锁，但是不共享close-on-exec标志。
