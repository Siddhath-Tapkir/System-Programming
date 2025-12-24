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
    char DirDest[FILE_NAME];
    char DirSor[FILE_NAME];
    DIR *dp = NULL;
    char str[FILE_NAME];
    char str2[FILE_NAME];
    int iCount = 0, iRet = 0;

    memset(DirDest,'\0',FILE_NAME);
    memset(DirSor,'\0',FILE_NAME);
    memset(str,'\0',FILE_NAME);
    memset(str2,'\0',FILE_NAME);

    printf("Enter Source Directory name\n");
    scanf(" %[^\n]s",DirSor);
    printf("Enter Destination directory name\n");
    scanf(" %[^\n]s",DirDest);

    dp = opendir(DirSor); // ./test

    if(NULL == dp)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    while(file = readdir(dp))
    {   
        if(file->d_type == DT_REG)
        {
            sprintf(str,"./%s/%s",DirSor,file->d_name);
            sprintf(str2,"./%s/%s",DirDest,file->d_name);
            iRet = rename(str,str2);
            
            if(iRet == 0)
            {
                iCount++;
            }
            else
            {
                printf("%s\n",strerror(errno));
            }
        }
    }
    
    printf("%d files moved\n",iCount);
    
    closedir(dp);

    return 0;
}