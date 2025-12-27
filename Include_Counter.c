#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<dirent.h>
#include<stdbool.h>

#define DIRECTORY_NAME_SIZE 30
#define FILESIZE 1024
#define INCLUDE_SIZE 8
int main(int argc, char *argv[])
{
    if(argc <= 1)
    {
        printf("Give complete parameter\n");
        return 1;
    }
    char DirName[DIRECTORY_NAME_SIZE];
    struct dirent *Files = NULL;
    char Buff[INCLUDE_SIZE];
    char path[FILESIZE];
    DIR *dp = NULL;
    int iCount = 0;
    int fd = 0;

    memset(DirName,'\0',DIRECTORY_NAME_SIZE);
    memset(Buff,'\0',INCLUDE_SIZE);
    memset(path,'\0',FILESIZE);

    dp = opendir(argv[1]);

    if(NULL == dp)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    while(Files = readdir(dp))
    {
        strcpy(DirName,argv[1]);
        if(Files->d_type == DT_REG)
        {
            sprintf(path,"./%s/%s",DirName,Files->d_name); //./Data/sync_1.c

            fd = open(path,O_RDONLY);

            if(fd != -1)
            {
                while(read(fd,Buff,1) == 1)
                {
                    if(Buff[0] == 'i')
                    {
                        if(read(fd,Buff + 1,6) == 6)
                        {
                            Buff[0] = 'i';
                            Buff[7] = '\0';
                            if(strcmp(Buff, "include") == 0)
                            {
                                iCount++;
                                memset(Buff,'\0',INCLUDE_SIZE);
                            }
                        }
                    }
                }
                close(fd);
            }
        }
    }

    closedir(dp);

    printf("%d\n",iCount);

    return 0;
}
