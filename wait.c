#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t child_pid;
	pid_t my_pid;
	int status;

	my_pid = getpid();
	printf("my pid is %u\n", my_pid);

	child_pid = fork();
	if(child_pid == -1)
	{
		perror("error:");
		return(1);
	}

	if(child_pid == 0)
	{
		printf("my pid is %u\nwait for me, wait for me\n", my_pid);
		sleep(3);
	}
	else
	{
		wait(&status);
		printf("my pid is %u %u\noh it is better now\n", my_pid, child_pid);
	}
	return(0);
}
