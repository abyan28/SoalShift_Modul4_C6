#define FUSE_USE_VERSION 28
#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <sys/time.h>


static const char *dirpath = "/home/v28cyber/Documents";

static int xmp_getattr(const char *path, struct stat *stbuf)

{

	int res;
	char fpath[1000];
	char newFile[100];

  	printf("path   : %s, len: %d\n", path, strlen(path));

	if (strcmp(path, "/") != 0) {
		memcpy(newFile, path, strlen(path) - 4);
		newFile[strlen(path) - 4] = '\0';
	}
	else 
	{
		memcpy(newFile, path, strlen(path));
  	}

	printf("newFile: %s\n", newFile);
	sprintf(fpath,"%s%s",dirpath, newFile);
	res = lstat(fpath, stbuf);

	if (res == -1)
		return -errno;

	return 0;

}

