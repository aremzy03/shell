#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(void)
{
	pid_t pid;
	char *argv[] = {"/bin/ls",NULL, NULL};
	int exe, count;

	pid = fork();
	if (pid == -1)
	{
		perror("Error:\n");
		return (1);
	}
	printf("my pid is %u\n", pid);
	
	if (pid == 0)
	{
		exe = execve(argv[0], argv, NULL);
		if(exe == -1)
		{
			perror("Error\n");
			return(1);
		}
	}
	else
	{
		wait(NULL);
	}
	printf("command five times\n");
	return(0);
}
