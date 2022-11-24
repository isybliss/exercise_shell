#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *buffer = NULL;
	size_t len = 0;
	char prompt;
	char delim[] = " ";
	char *ptr;

	printf("$ ");

	prompt = getline(&buffer, &len, stdin);
	if(prompt == -1)
		perror("ERROR");
	ptr = strtok(buffer, delim);
	while(ptr)
	{
		printf("%s\n", ptr);
		ptr = strtok(NULL, delim);
	}
	free(buffer);
	return(0);
}
