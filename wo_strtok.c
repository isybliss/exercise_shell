#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *search_token(char *string, char *delim)
{
	static char *remember = NULL;
	int s_length = 0;
	int i = 0;
	int search_hit = 0;

	if(delim == NULL)
	       return NULL;
	if((string == NULL) && (remember == NULL))
		return (NULL);
	if(string == NULL)
		string = remember;
	s_length = strlen(string) + 1;
	for(i = 0; i < s_length; i++)
	{
		if(string[i] == delim[0])
		{
			search_hit = 1;
			break;
		}
	}
	if(search_hit != 1)
	{
		remember = NULL;
		return (string);
	}
	string[i] = '\0';
	if((string + i + 1) != NULL)
		remember = string + i + 1;
	else
		remember = NULL;

	return (string);
}
		

int main(void)
{
	char *string;
	size_t size = 100;
	size_t prompt;
	char *delim = " ";
	char *token;
	//unsigned count = 0;

	printf("$ ");

	string = malloc(sizeof(char) * size);
	if(string == NULL)
	{
		free(string);
		perror("unable to allocate string");
	}
	prompt = getline(&string, &size, stdin);
	if (prompt == -1)
		perror("Error");
	else
		printf("%s\n", string);

	token = search_token(string, delim);
	//count++;
	while(token)
	{
		printf("token number: %s\n", token);
		token = search_token(NULL, delim);
		//count++;
	}
	free(string);
	return (0);
}
