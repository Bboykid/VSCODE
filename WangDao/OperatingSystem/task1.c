#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	pid_t pid1,pid2;
	pid1=fork();
	if(pid1<0)
	{
		printf("false");
		exit(1);
	}
	else if(pid1==0)    //如果pid为0则表示当前执行的是子进程
	{
		printf("child 1:%d\n",getpid());
	}
	else    //否则为父进程
	{
		pid2=fork();
		if(pid2<0)
		{
			printf("false");
			exit(1);
		}
		else if(pid2==0)//如果pid为0则表示当前执行的是子进程
		{
			printf("child 2:%d\n",getpid());		
		}
		else
		{
			printf("father:%d\n",getpid());		
		}
	}
	return 0;
}
