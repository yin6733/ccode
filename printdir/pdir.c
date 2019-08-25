#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>

void print_path(const char *);
void print_dir(const char *);

int main(int argc, char* argv[]) {
	if(argc == 1) {
		print_path(".");
	} else {
		print_path(argv[1]);
	}
	return 0;
}

void print_path(const char *name) {
	struct stat sb;
	int ret = stat(name, &sb);
	if(ret == -1) {
		perror("get file stat fail");
		return;
	}
	if((sb.st_mode & S_IFMT) == S_IFDIR) {
		print_dir(name);
		return;
	}
	printf("%20s\t%ld\n", name, sb.st_size);
}

void print_dir(const char *dir) {
	char path[256];
	DIR *dp;
	struct dirent *sdp;
	dp = opendir(dir);
	if(dp == NULL) {
		perror("open dir fail");
		return;
	}
	while(sdp = readdir(dp)) {
		if(strcmp(sdp->d_name, ".") == 0 || strcmp(sdp->d_name, "..") == 0) {
			continue;
		}
		sprintf(path, "%s/%s", dir, sdp->d_name);
		print_path(path);
	}
	closedir(dp);
}
