#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

void printStat(char *path){
	struct stat buffer;
	int debug = stat(path, &buffer);

	//printf("Debug: %i\n", debug);

	struct tm tm = *localtime(&buffer.st_atime);
	

	printf("File Size: %lli bytes\n", buffer.st_size);
	printf("Permissions: %#o\n", buffer.st_mode);
	printf("Last Access: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

}

int main(){
	char file[30] = "stat.c";
	printStat(file);

}