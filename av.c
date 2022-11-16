#include <stdio.h>

int main(int __attribute__((__unused__)) ac, char **av)
{
	while(*++av)
		printf("%s\n", *av);
	return (0);
}
