#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *string;
	size_t size = 100;
	size_t prompt;
	char delim[] = " ";
	char *ptr;

	string = malloc(sizeof(char) * size);
	if (string == NULL)
	{
		perror("unable to allocate string");
		free(string);
	}
	printf("$ ");
	prompt = getline(&string, &size, stdin);
	if (prompt == -1)
		perror("ERROR");
	printf("%s\n", string);

	ptr = strtok(string, delim);

	while (ptr)
	{
		printf("%s\n", ptr);
		ptr = strtok(NULL, delim);
	}

	free(string);
	return (0);
}
