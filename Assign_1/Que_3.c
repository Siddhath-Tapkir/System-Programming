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
    int iRet = 0;

    memset(str,'\0',FILE_NAME);
    memset(cMode,'\0',MODE);

    printf("Enter a file name\n");
    scanf("%[^\n]s",str);
    printf("Enter the mode you want to open the file in\nR,W,X\n");
    scanf(" %[^\n]s",cMode);

    if((strcmp(cMode,"R")) == 0)
    {
        fd = open(str,O_RDONLY);

        if(fd == -1)
        {
            printf("%s\n",strerror(errno));
            return -1;
        }

        iRet = access(str,R_OK | F_OK);

        if(iRet == -1)
        {
            printf("%s\n",strerror(errno));
        }
        else
            printf("File is readable\n");
    }
    else if((strcmp(cMode,"W")) == 0)
    {
        fd = open(str,O_WRONLY);

        if(fd == -1)
        {
            printf("%s\n",strerror(errno));
            return -1;
        }

        iRet = access(str,W_OK | F_OK);

        if(iRet == -1)
        {
            printf("%s\n",strerror(errno));
        }
        else
            printf("File is writable\n");
    }
    else if((strcmp(cMode,"X")) == 0)
    {
        fd = open(str,O_RDWR);

        if(fd == -1)
        {
            printf("%s\n",strerror(errno));
            return -1;
        }

        iRet = access(str,X_OK | F_OK);

        if(iRet == -1)
        {
            printf("%s\n",strerror(errno));
        }
        else
            printf("File is executable\n");
    }

    printf("File was successfully open with fd : %d\n",fd);

    close(fd);

    return 0;
}