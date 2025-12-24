#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>

#define FILE_SIZE 1024

int main(int argc, char* argv[])
{
    if(argc <= 1)
    {
        printf("No parameters given\n");
        return 1;
    }
    int BYTES = 0;
    int fd = 0;
    int iRet = 0 ;
    char Buff[FILE_SIZE];

    memset(Buff,'\0',FILE_SIZE);

    printf("Enter the bytes you want to write in the file\n");
    scanf(" %[^\n]s",Buff);

    fd = open(argv[1],O_WRONLY | O_CREAT | O_APPEND,0777);

    if(fd == -1)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    BYTES = write(fd,Buff,strlen(Buff));

    printf("%d bytes written from the file\n",BYTES);

    return 0;
}