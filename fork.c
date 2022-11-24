#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t my_pid; //current process id  
	pid_t child_pid;

	printf("Before fork\n");
	my_pid = getpid(); //current process id
	printf("%u\n", my_pid);
	child_pid = fork(); //to create a new child process
	if(child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	printf("After fork\n");
	my_pid = getpid();
	printf("My pid is %u\n", my_pid);

	if(child_pid == 0)
	{
		printf("(%u) this process is child's\n", my_pid);
	}
	else
	{
		printf("(%u) this process is father's (%u)\n", my_pid, child_pid); //if it retuns the child_pid, it is the fathers process
	}
	return(0);
	//the current process runs first to create a new child process thereby becoming the parent process
	//then the new child process is run.
}
