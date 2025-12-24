#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>

#define FILE_NAME 256

int main()
{
    struct dirent *file = NULL;
    struct stat sobj;
    char DirSor[FILE_NAME];
    DIR *dp = NULL;
    char str[FILE_NAME];
    int iCount = 0, iRet = 0;

    memset(DirSor,'\0',FILE_NAME);
    memset(str,'\0',FILE_NAME);

    printf("Enter Directory name\n");
    scanf(" %[^\n]s",DirSor);

    dp = opendir(DirSor);

    if(NULL == dp)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    while(file = readdir(dp))
    {   
        if((file->d_type == DT_REG))
        {
            sprintf(str,"%s/%s",DirSor,file->d_name);
            iRet = stat(str,&sobj);

            if(iRet == -1)
            {
                printf("%s\n",strerror(errno));
                return -1;
            }

            if(sobj.st_size == 0)
            {
                unlink(str);
                iCount++;
            }
        }
    }
    
    printf("%d files deleted\n",iCount);
    
    closedir(dp);

    return 0;
}