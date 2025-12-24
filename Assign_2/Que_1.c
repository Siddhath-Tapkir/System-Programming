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

    fd = open(argv[1],O_RDONLY);

    if(fd == -1)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    while(iRet = (read(fd,Buff,FILE_SIZE)) != 0)
    {
        printf("%s",Buff);
        BYTES += strlen(Buff);
    }

    printf("\n%d bytes read from the file\n",BYTES);


    return 0;
}