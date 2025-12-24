#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

#define FILE_NAME 30
int main()
{
    char str[FILE_NAME];
    int fd = 0;

    memset(str,'\0',FILE_NAME);

    printf("Enter a file name\n");
    scanf("%[^\n]s",str);

    fd = open(str,O_RDONLY);

    if(fd == -1)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    printf("File was successfully open with fd : %d\n",fd);

    close(fd);

    return 0;
}