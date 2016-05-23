#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main()
{ 
	//int open(const char *pathname, int flags,mode_t mode);
	int fd = open("./file",O_CREAT | O_RDWR,0644);//If  the file does not exist it will be created
	if(fd == -1)
	{
		perror("open()");
		return -1;
	}
	close(1);
	int new_fd = dup(fd);
	//int new_fd = dup2(fd,1);
	if(new_fd == -1)
	{
		perror("dup()");
		return -1;
	}
	printf("new_fd: %d\n",new_fd);

	char buf[1024];
	while(1)
	{
		memset(buf,'\0',sizeof(buf));
		fgets(buf,sizeof(buf),stdin);
		if(strncmp("quit",buf,4) == 0)
		  break;
		printf("%s",buf);
		fflush(stdout);
	}
	close(fd);
	close(new_fd);
	return 0;
}
