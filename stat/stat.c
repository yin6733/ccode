#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>

int main() {
	struct stat buf;
	stat("./test.txt", &buf);
	printf("the file size is: %ld\n", buf.st_size);
	printf("the file mode is: %o\n", buf.st_mode);
	return 0;
}
