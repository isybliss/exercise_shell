#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *buffer = NULL;
	size_t len = 0;
	ssize_t prompt;

	printf("$ ");

	prompt = getline(&buffer, &len, stdin);
	if(prompt != -1)
	{
		printf("%s", buffer);
	}
	free(buffer);
	return(0);
}
