#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>

#define FILE_NAME 30
int main()
{
    char str[FILE_NAME];
    int iRet = 0;

    memset(str,'\0',FILE_NAME);

    printf("Enter file name\n");
    scanf(" %[^\n]s",str);

    struct stat sobj;

    iRet = stat(str,&sobj);

    if(iRet == -1)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    printf("Size of the file is %ld\n",sobj.st_size);
    printf("Inode of the file is %ld\n",sobj.st_ino);
    //printf("Permission of the file is %ld\n",sobj.st_);
    printf("Hardlinks of the file is %ld\n",sobj.st_nlink);
    printf("Owner UID of the file is %d\n",sobj.st_uid);
    printf("Owner GID of the file is %d\n",sobj.st_gid);
    printf("File type is %d\n",sobj.st_mode);
    printf("Last access time%ld\n",sobj.st_atim);
    printf("Last modified time%ld\n",sobj.st_mtim);

    return 0;
}