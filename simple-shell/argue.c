#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
	int count;

	if (ac < 2)
	{
		printf("usecase: ./argue argument1 argument2 ...\n");
		exit(0);
	}
	count = 1;
	while(*av[count] != '\0')
	{
		printf("%s\n", av[count]);
		count++;
	}
	return 0;
}
