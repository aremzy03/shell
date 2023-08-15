#include <stdio.h>
#include <unistd.h>
int main(void)
{
	pid_t myppid;
	myppid = getppid();
	printf("this is your PPID %d\n", myppid);
	return 0;
}
