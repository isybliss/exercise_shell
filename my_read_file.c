#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *stream;
	char *buffer = NULL;
	size_t len = 0;
	ssize_t nread;

	printf("$ ");

	if(argc != 2)
	{
		fprintf(stderr, "Usuage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if(stream == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	nread = getline(&buffer, &len, stream);
	if(nread != -1)
	{
		fwrite(buffer, nread, 1, stdout);
	}
	free(buffer);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
