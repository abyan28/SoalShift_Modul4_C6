#define FUSE_USE_VERSION 28
#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <sys/time.h>

//alamat file system yang akan di mount
static const char *dirpath = "/home/v28cyber/Documents";

/*fungsi untuk mengambil atribut. fungsi ini akan dipanggil
setiap fungsi xmp readdir membaca isi direktori*/
static int xmp_getattr(const char *path, struct stat *stbuf)
{

	int res;
	char fpath[1000];

  	sprintf(fpath,"%s%s",dirpath, path);
	res = lstat(fpath, stbuf);

	if (res == -1)
		return -errno;

	return 0;
}


