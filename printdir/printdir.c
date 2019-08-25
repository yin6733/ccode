#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>

void print_dir(DIR *);
int is_dir(char *);
int is_reg(char *);

int main(int argc, char *argv[]) {
	DIR *dp = opendir(argv[1]);
	if(dp == NULL) {
		perror("opendir fail");
		exit(1);
	}
	print_dir(dp);
	return 0;
}

void print_dir(DIR *dp) {
	struct dirent *de;
	DIR *dp2;
	char *path = getcwd(NULL, 0);
	char a_path[256];
	if(path == NULL) {
		perror("get path error");
		exit(1);	
	}
	while(de = readdir(dp)) {
		if(de->d_name == "." || de->d_name == "..") {
			continue;
		}
		sprintf(a_path, "%s/%s", path, de->d_name);
		if(is_reg(a_path)) {
			printf("%s\t", de->d_name);
		} else if(is_dir(a_path)) {
			printf("\n%s: \n", de->d_name);
			dp2 = opendir(path);
			if(dp2 == NULL) {
				perror("open dir 2 fail");
				exit(1);
			}
			print_dir(dp2);
		}
	}
}

int is_dir(char *path) {
	struct stat sb;
	stat(path, &sb);
	return ((sb.st_mode & S_IFMT) == S_IFDIR);
}

int is_reg(char *path) {
	struct stat sb;
	stat(path, &sb);
	return ((sb.st_mode & S_IFMT) == S_IFREG);
}
