#include <stdio.h>
#include <string.h>
char *str_tok(char *str, const char *token)
{
	int count;
	count = 0;
	while(str[count] != '\0')
	{
		if (str[count] == token)
		{
			return ('\0');
		}
		else
			return (str[count]);
		count++;
	}
}
		
int main(void)
{
	char str[] = "Aremzy-Boss";
	char* token, token2;

	token  = strtok(str, "-");
	token2 = str_tok(str, "-");
	while(token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, "-");
	}
	while(token2 != NULL)
	{
		printf("%s\n", token2);
		token2 = str_tok(NULL, "-");
	}
	return 0;
}
