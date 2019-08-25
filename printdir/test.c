#include<stdio.h>
#include<sys/stat.h>
#include<>

int main() {
	struct stat sb;
	stat(".", &sb);
	if(sb.st_mode & S_IFMT == )
	return 0;
}
