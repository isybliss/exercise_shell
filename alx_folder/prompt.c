#include <stdio.h>
#include <stdlib.h>

int main()
{
	size_t prompt;
	size_t size = 5;
	char *buffer;

	printf("$ ");

	buffer = malloc(sizeof(char) * size);
	if (!buffer)
	{
		perror("unable to allocate buffer");
		exit(1);
	}

	prompt = getline(&buffer, &size, stdin);

	if (prompt == -1)
		puts("Error!");
	else
	{
		printf("%s\n", buffer);
		printf("length of string: %lu characters\n", prompt);
	}
	free(buffer);
	return (0);
}
		
