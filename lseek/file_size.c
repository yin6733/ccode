#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#define N 1

int main()
{
	char buf[N];
	int fd = open("./test.txt", O_RDONLY);
	if(fd == -1)
	{
		perror("open fail");
		exit(1);
	}
	int size = lseek(fd, 0, SEEK_END);
	printf("the file size is %d\n", size);
	int i, char_pos;
	for(i=0; i<size; i++)
	{
		char_pos = lseek(fd, i, SEEK_SET);
		read(fd, buf, 1);
		printf("the %d char is: ", i);
		write(STDOUT_FILENO, buf, 1);
	}
	close(fd);
	return 0;
}
