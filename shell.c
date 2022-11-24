#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

/*void _exec(char *av[])
{
	int nexecve;	
	nexecve = execve(av[0], av, NULL);
	if(nexecve == -1)
		printf("failed to execute\n");
} */

int main(int ac, char *argv[])
{
	pid_t child_pid = 1;
	int status, i, j, k = 0;
	char *buffer = NULL;
	size_t len = 0;
	ssize_t prompt;
	int nexecve;
	char *args[ac];

	printf("cis is fun$ ");

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
		/*rintf("#cis if fun$ ");*/
		prompt = getline(&buffer, &len, stdin);
		if(prompt != -1)
		{
			/*if(ac < 2)
			{
				perror("Error:");
			} */
			for(j = 1; j <= ac; j++)
			{
				args[k] = argv[j];
				k++;
			}
			nexecve = execve(args[0], args, NULL);
			if(nexecve == -1)
				printf("failed to execute");
		}
		sleep(3);
	}
	return(0);
}

