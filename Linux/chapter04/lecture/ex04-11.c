#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    struct stat finfo;
    char *fname;

    if (argc > 1)
        fname = argv[1];
    else
        fname = argv[0];

    if (stat(fname, &finfo) == -1) {
        fprintf(stderr, "Couldn't stat %s.\n", fname);
        exit(1);
    }

    puts(fname);
    printf("ID of device: %lu\n", finfo.st_dev);
    printf("Inode number: %lu\n", finfo.st_ino);
    printf("File mode: %o\n", finfo.st_mode);
    printf("Num of links: %lu\n", finfo.st_nlink);
    printf("User ID: %d\n", finfo.st_uid);
    printf("Group ID: %d\n", finfo.st_gid);
    printf("Files size: %ld\n", finfo.st_size);
    printf("Last access time: %lu\n", finfo.st_atim);
    printf("Last modify time: %lu\n", finfo.st_mtim);
    printf("Last stat change: %lu\n", finfo.st_ctim);
    printf("I/O Block size: %ld\n", finfo.st_blksize);
    printf("Num of blocks: %ld\n", finfo.st_blocks);

    return 0;
}
