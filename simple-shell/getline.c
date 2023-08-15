#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int n;
	char* line;
	size_t size;

	printf("$ ");
	size = 100;
	line = malloc(size * sizeof(char));
	if(line == NULL)
	{
		perror("cannot allocate buffer");
		exit(0);
	}
	n = getline(&line, &size, stdin);
	if(n == -1)
	{
		printf("error");
		return(1);
	}
	else
	{
		printf("%s", line);
	}
	return (1);
}
