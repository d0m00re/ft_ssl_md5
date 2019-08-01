#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
	char buff[200];
	bzero(buff, 200);
	while (read(0, buff, 1) && buff[0] != 10)
		printf("->%c|%d\n", buff[0], buff[0]);
	return (1);
}
