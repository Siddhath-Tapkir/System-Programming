#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>

#define FILE_NAME 256

int main()
{
    struct dirent *file = NULL;
    char fName[FILE_NAME];
    char Dir[FILE_NAME];
    DIR *dp = NULL;

    memset(fName,'\0',FILE_NAME);
    memset(Dir,'\0',FILE_NAME);

    printf("Enter Directory name\n");
    scanf(" %[^\n]s",Dir);
    printf("Enter File name\n");
    scanf(" %[^\n]s",fName);

    dp = opendir(Dir);

    if(NULL == dp)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    while(file = readdir(dp))
    {
        if(strcmp(fName,file->d_name) == 0)
        {
            printf("%s found in %s directory\n",file->d_name,Dir);
            break;
        }
    }

    if(file == NULL)
    {
        printf("No file name was found\n");
    }

    closedir(dp);

    return 0;
}