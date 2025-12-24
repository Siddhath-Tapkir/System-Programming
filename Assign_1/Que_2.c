#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

#define FILE_NAME 30
#define MODE 3
int main()
{
    char str[FILE_NAME];
    char cMode[MODE];
    int fd = 0;

    memset(str,'\0',FILE_NAME);
    memset(cMode,'\0',MODE);

    printf("Enter a file name\n");
    scanf("%[^\n]s",str);
    printf("Enter the mode you want to open the file in\nR,W,RD,A\n");
    scanf(" %[^\n]s",cMode);

    if((strcmp(cMode,"R")) == 0)
    {
        fd = open(str,O_RDONLY | O_CREAT,0777);

        if(fd == -1)
        {
            printf("%s\n",strerror(errno));
            return -1;
        }
    }
    else if((strcmp(cMode,"W")) == 0)
    {
        fd = open(str,O_WRONLY | O_CREAT,0777);

        if(fd == -1)
        {
            printf("%s\n",strerror(errno));
            return -1;
        }
    }
    else if((strcmp(cMode,"RD")) == 0)
    {
        fd = open(str,O_RDWR | O_CREAT,0777);

        if(fd == -1)
        {
            printf("%s\n",strerror(errno));
            return -1;
        }
    }
    else if((strcmp(cMode,"A")) == 0)
    {
        fd = open(str,O_WRONLY | O_APPEND | O_CREAT,0777);

        if(fd == -1)
        {
            printf("%s\n",strerror(errno));
            return -1;
        }
    }

    printf("File was successfully open with fd : %d\n",fd);

    close(fd);

    return 0;
}