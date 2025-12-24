#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

#define FILE_NAME 30
#define FILE_SIZE 1024
int main()
{
    char str[FILE_NAME];
    char Buff[FILE_SIZE];
    int byte = 0;
    int fd = 0;
    int iRet = 0;

    memset(Buff,'\0',FILE_SIZE);
    memset(str,'\0',FILE_NAME);

    printf("Enter a file name\n");
    scanf("%[^\n]s",str);
    printf("Enter number of bytes you want to read from the file\n");
    scanf("%d",&byte);

    fd = open(str,O_RDONLY);

    if(fd == -1)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }
/*
    while((iRet = read(fd,Buff,byte)) < byte)
    {
        //Buff[iRet] = '\0';
        printf("%s\n",Buff);
    }
*/
    iRet = read(fd,Buff,byte);

    Buff[iRet] = '\0';

    write(1,Buff,iRet);

    close(fd);

    return 0;
}