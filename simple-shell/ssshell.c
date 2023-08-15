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
	char *delim = " \n", cat[200] = "/bin/";
	int argc = 0, i = 0, command, run;
	int line;


	printf("$ ");
	/*GETLINE FUNCTION TO GET INPUT*/
	command = getline(&cmd, &n, stdin);
	if (command == -1)
	{
		perror("Error1\n");
		exit(1);
	}
	cmd_cpy = strdup(cmd);//A COPY OF THE CMD TO SPLIT WITH STRTOK
	token = strtok(cmd, delim);
	/*GETTING THE SIZE OF ARGUEMENTS AND PRINTING IT OUT*/
	while (token)
	{
		token = strtok(NULL, delim);
		argc++;
	}
	printf("%d\n", argc);
	/*ALLOCATING MEMORY FOR THE COMMANDS AND SPLITTING IT TO AN ARRAY(argv)*/
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
	/*MAKING A COPY OF argv FOR THE execve() FUNCTION*/
	if (strstr(argv[0], cat) != NULL)
	{
		exe[0] = strdup(argv[0]);
	}
	else
	{
		strcat(cat, argv[0]);//constructing the PATH FOR the command (/bin/)
		exe[0] = strdup(cat);
	}
	for (i = 1; argv[i] != NULL; i++)
	{
		exe[i] = strdup(argv[i]);
		printf("exe[%d] is %s\n", i, exe[i]);
	}
	exe[i] = NULL;
	printf("%s\n", cat);
	/* CREATING A NEW PROCESS AND EXECUTING THE COMMAND*/
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
	/*FREEING ALLOCATED MEMORY*/
	free(cmd), free(cmd_cpy), free(argv); //free(cat);
	
	for (i = 0; exe[i] != NULL; i++)
	{
		free(exe[i]);
	}
	
	return (0);
}
