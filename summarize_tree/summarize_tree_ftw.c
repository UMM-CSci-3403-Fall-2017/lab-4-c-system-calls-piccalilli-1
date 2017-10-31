#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <ftw.h>

static int num_dirs, num_regular;

static int callback(const char * fpath, const struct stat * sb, int typeflag){
	//Check if typeflag is equal to FTW_W
	//if it is, then it is a regular file, so increment num_regular
	if(typeflag == FTW_F){
			num_regular++;
			return 0;
	}
	//Check if typeflag is equal to FTW_D
	//if it is, then it is a directory, so increment num_dirs
	else if(typeflag == FTW_D){
			num_dirs++;
			return 0;
	}
	//else, do not increment anything
	else{
			return 0;
	}




}

#define MAX_FTW_DEPTH 16

int main(int argc, char** argv){

	num_dirs = 0;
	num_regular = 0;

	ftw(argv[1], callback, MAX_FTW_DEPTH);

	printf("There were %d directories. \n", num_dirs);
	printf("There were %d regular files.\n", num_regular);

}
