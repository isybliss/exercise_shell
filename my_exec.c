#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char *av[])
{
	int n_execve, i, k = 0;
	char *cmp[ac];

	if(ac < 2)
	{
		printf("not enough commands to run execve\n");
		exit(1);
	}

	for(i = 1; i <= ac; i++)
	{
		cmp[k] = av[i];
		k++;
	}

	printf("Before execve\n");

	n_execve = execve(cmp[0], cmp, NULL);
	if(n_execve == -1)
		perror("ERROR:");
	return (0);
}
