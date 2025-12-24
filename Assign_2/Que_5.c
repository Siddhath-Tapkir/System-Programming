#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>
#include<dirent.h>
#include<sys/types.h>

int main(int argc, char* argv[])
{
    if(argc <= 1)
    {
        printf("No parameters given\n");
        return 1;
    }

    struct stat sobj;
    DIR *dp = NULL;
    struct dirent *Files = NULL;
    int iLarge = 0;
    char fName[256];
    char path[1024];

    dp = opendir(argv[1]);

    memset(fName,'\0',256);
    memset(path,'\0',1024);

    if(NULL == dp)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    while(Files = readdir(dp))
    {
        if(Files->d_type == DT_REG)
        {
            sprintf(path,"%s/%s",argv[1],Files->d_name);
            stat(path,&sobj);

            if(iLarge < sobj.st_size)
            {
                iLarge = sobj.st_size;
                strcpy(fName,Files->d_name);
            }
        }
    }

    printf("The largest file in bytes in the directory is : %s with %d bytes\n",fName,iLarge);

    closedir(dp);

    return 0;
}