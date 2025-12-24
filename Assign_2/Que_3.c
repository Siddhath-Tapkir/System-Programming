#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>
#include<dirent.h>
#include<sys/types.h>

int main(int argc, char* argv[])
{
    if(argc <= 1)
    {
        printf("No parameters given\n");
        return 1;
    }

    DIR *dp = NULL;
    struct dirent *Files = NULL;

    dp = opendir(argv[1]);

    if(NULL == dp)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    while(Files =  readdir(dp))
    {
        if(Files->d_type == DT_REG)
        {
            printf("%s\n",Files->d_name);
        }
    }

    closedir(dp);

    return 0;
}