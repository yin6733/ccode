#include<stdio.h>
#include<unistd.h>
#include<dirent.h>

int main() {
	DIR *dp;
	struct dirent *dentry;
	dp = opendir("./");
	while(dentry = readdir(dp)) {
		printf("%s\n", dentry->d_name);	
	}
	closedir(dp);
}
