#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int i = 0, nexec, status;
	pid_t child_pid;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	child_pid = 1;

	while(i < 3 && child_pid != 0)
	{
		child_pid = fork();
		if(child_pid == -1)
		{
			perror("Error:");
			return(1);
		}
		wait(&status);
		i++;
	}

	if(child_pid == 0)
	{
		nexec = execve(argv[0], argv, NULL);
		if(nexec == -1)
		{
			perror("Error:");
		}
		sleep(6);
	}
	return(0);
}


