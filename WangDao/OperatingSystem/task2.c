#include<signal.h>
#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

pid_t pid1,pid2;

void fun(int sig)
{
	kill(pid1,SIGUSR1);
	kill(pid2,SIGUSR2);
	
}

void fun1(int sig)
{
	printf("child1 is killed !\n");
}

void fun2(int sig)
{
	printf("child2 is killed !\n");
}

int main(int argc(),char *argv[])
{
	pid1=fork();
  	if(pid1>0)
 	{
		pid2=fork();
		if(pid2>0)
		{
			signal(SIGALRM,fun);
			alarm(2);
			wait(NULL);
			wait(NULL);
			printf("parent process exit!\n");
		}
		if(pid2==0)
		{
			signal(SIGUSR2,fun2);
			pause();
		}
	}
	if(pid1==0)
	{
		signal(SIGUSR1,fun1);
		pause();	
 	}
	return 0;
}
