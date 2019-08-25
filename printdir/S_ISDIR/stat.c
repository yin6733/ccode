#include<stdio.h>
#include<sys/stat.h>

int main(int argc, char *argv[]) {
	struct stat st;
	stat(argv[1], &st);
	printf("%d\n", S_ISDIR(st.st_mode));
	printf("%d\n", ((S_IFMT & st.st_mode) == S_IFDIR));
}
