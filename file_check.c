#include <stdio.h>
#include <sys/stat.h>

int main(void)
{
    struct stat file_stat;

    if (stat("school", &file_stat) == 0)
    {
        printf("school file exists\n");

        if (file_stat.st_size > 0)
        {
            printf("school file is not empty\n");
        }
        else
        {
            printf("school file is empty\n");
        }

        if (S_ISREG(file_stat.st_mode))
        {
            printf("school is a regular file\n");
        }
    }
    else
    {
        printf("school file does not exist\n");
    }

    return 0;
}
