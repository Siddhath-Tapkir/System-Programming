#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

#define FILE_NAME 256
#define BUFFER_SIZE 1024

int main()
{
    char Source[FILE_NAME];
    char Dest[FILE_NAME];
    char Buff[BUFFER_SIZE];
    int iRet = 0;
    int source_fd = 0;
    int dest_fd = 0;

    memset(Buff,'\0',BUFFER_SIZE);
    memset(Source,'\0',FILE_NAME);
    memset(Dest,'\0',FILE_NAME);

    printf("Enter source file name\n");
    scanf(" %s",Source);

    printf("Enter Destination file name\n");
    scanf(" %s",Dest);

    source_fd = open(Source,O_RDONLY);

    if(-1 == source_fd)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    dest_fd = open(Dest,O_WRONLY | O_TRUNC | O_CREAT,0777);

    if(-1 == dest_fd)
    {
        printf("%s\n",strerror(errno));
        close(source_fd);
        return -1;
    }

    while((iRet = read(source_fd,Buff,BUFFER_SIZE)) > 0)
    {
        write(dest_fd,Buff,iRet);
    }

    iRet = fsync(dest_fd);

    if(-1 == iRet)
    {
        printf("%s\n",strerror(errno));

        close(source_fd);
        close(dest_fd);
        return -1;
    }

    close(source_fd);
    close(dest_fd);

    return 0;
}