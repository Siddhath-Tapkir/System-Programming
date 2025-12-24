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

    DIR *dp = NULL;
    struct dirent *Files = NULL;

    dp = opendir(argv[1]);

    if(NULL == dp)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    while(Files =  readdir(dp))
    {
        if(Files->d_type == DT_REG)
        {
            printf("%s\t",Files->d_name);
            printf("Regular File\n");
        }
        else if(Files->d_type == DT_BLK)
        {
            printf("%s\t",Files->d_name);
            printf("Block Device file\n");
        }
        else if(Files->d_type == DT_CHR)
        {
            printf("%s\t",Files->d_name);
            printf("Character Device file\n");
        }
        else if(Files->d_type == DT_DIR)
        {
            printf("%s\t",Files->d_name);
            printf("Directory file\n");
        }
        else if(Files->d_type == DT_FIFO)
        {
            printf("%s\t",Files->d_name);
            printf("Pipe\n");
        }
        else if(Files->d_type == DT_LNK)
        {
            printf("%s\t",Files->d_name);
            printf("Symbolic link file\n");
        }
        else if(Files->d_type == DT_SOCK)
        {
            printf("%s\t",Files->d_name);
            printf("Socket file\n");
        }
    }

    closedir(dp);

    return 0;
}