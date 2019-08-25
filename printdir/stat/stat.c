#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>

int main() {
	struct stat buf;
	stat("./test.txt", &buf);
	printf("%o\n", buf.st_mode);
	return 0;
}
