#include <stdio.h>
#include <unistd.h>
int main(void)
{
	pid_t mypid;
	mypid = getpid();
	printf("My pid is %d\n", mypid);
	return 0;
}
