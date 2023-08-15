   #include <stdio.h>
   #include <unistd.h>
   #include <sys/types.h>
   #include <sys/wait.h>
   #include <stdlib.h>
   #include <string.h>

int main(void)
{
	pid_t mypid;
	size_t n;
	char **argv = NULL, *cmd = NULL, *cmd_cpy = NULL, *token = NULL;
	char *exe[100];
	char *delim = " \n", cat[100] = "/bin/";
	int argc = 0, i = 0, command, run;
	int line;


	printf("$ ");
	command = getline(&cmd, &n, stdin);
	if (command == -1)
	{
		perror("Error1\n");
		exit(1);
	}
	cmd_cpy = strdup(cmd);
	token = strtok(cmd, delim);
	while (token)
	{
		token = strtok(NULL, delim);
		argc++;
	}
	printf("%d\n", argc);
	argv = malloc(sizeof(char* ) * (argc + 1));
	token = strtok(cmd_cpy, delim);
	i = 0;
	while (token)
	{
		argv[i] = token;
		token = strtok(NULL, delim);
		printf("argv[%d] is %s\n", i, argv[i]);
		i++;
	}
	argv[i] = NULL;
	i = 0;
	while (argv[i])
	{
		if (i == 0)
		{
			strcat(cat, argv[i]);
			exe[i] = strdup(cat);
		}
		else
		{
			exe[i] = strdup(argv[i]);
			printf("%s\n", exe[i]);
		}
		i++;
	}
	i = 0;
	mypid = fork();
	if(mypid == -1)
	{
		perror("Error2\n");
		exit(1);
	}
	if (mypid == 0)
	{
		run = execve(exe[0], exe, NULL);
		if (run == -1)
		{
			perror("Error3\n");
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}
	free(cmd), free(cmd_cpy), free(argv); //free(cat);
	i = 0;
	while(exe[i])
	{
		free(exe[i]);
		i++;
	}
	
	return (0);
}
