#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int fd1 = open(argv[1], O_RDONLY);
	if(fd1 == -1)
	{
		perror("arg1 open error\n");
		exit(1);
	}
	int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd2 == -1)
	{
		perror("arg2 error\n");
		exit(1);
	}
	int n;
	char buf[1024];
	
	while(n = read(fd1, buf, 1024))
	{
		if(n == -1)
		{
			perror("read fail\n");
			exit(1);
		}
		if(write(fd2, buf, n) == -1)
		{
			perror("write fail\n");
			exit(1);
		}
	}

	close(fd1);
	close(fd2);

	return 0;
}
