#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

int main()
{
	int fn;
	fn = open("./text.txt", O_RDONLY | O_CREAT, 0511);
	printf("fn = %d,\nerrno=%d,\nerrinfo=%s\n", fn, errno, strerror(errno));
	return 0;
}
