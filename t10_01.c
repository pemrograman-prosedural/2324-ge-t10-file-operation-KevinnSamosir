#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/repository.h"

int main(int _argc, char **_argv) 
{
    int looping = 0;
    char command[100];
    struct student_t students[100];
    struct dorm_t dorms[100];
    int student_num = 0;
    int dorm_num = 0;

    char *Dorm[100];
    char *Student[100];
    
    
    FILE *drm;
    FILE *std;
    drm = fopen("./storage/dorm-repository.txt", "r");  
    std = fopen("./storage/student-repository.txt", "r");


    while (looping != 1 )
    {
        command[0] = '\0';
        short k = 0;
        while (1 == 1)
        {
            char i = getchar();
            if (i == '\n')
            {
                break;
            }
            if (i == '\r')
            {
                continue;
            }
            command[k] = i;
            command[++k] = '\0';
        }

        char *input = strtok(command, "#");

        if (strcmp(input, "student-print-all-detail") == 0)
        {
            for (int i = 0; i < student_num; i++)
            {
                if (students[i].dorm == NULL)
                {
                    if (students[i].gender != 1)
                    {
                        printf("%s|%s|%s|male|unassigned\n", students[i].id, students[i].name, students[i].year);
                    }
                    else
                    {
                        printf("%s|%s|%s|female|unassigned\n", students[i].id, students[i].name, students[i].year);
                    }
                }
                else
                {
                    if (students[i].gender != 1)
                    {
                        printf("%s|%s|%s|male|%s\n", students[i].id, students[i].name, students[i].year, students[i].dorm->name);
                    }
                    else
                    {
                        printf("%s|%s|%s|female|%s\n", students[i].id, students[i].name, students[i].year, students[i].dorm->name);
                    }
                }
            }
        }

        if (strcmp(input, "dorm-print-all-detail") == 0)
        {
            for (int i = 0; i < dorm_num; i++)
            {
                if (dorms[i].gender != 1)
                {
                    printf("%s|%d|male|%d\n", dorms[i].name, dorms[i].capacity, dorms[i].residents_num);
                }
                else
                {
                    printf("%s|%d|female|%d\n", dorms[i].name, dorms[i].capacity, dorms[i].residents_num);
                }
            }
        }

        if (strcmp(input, "---") == 0)
        {
            looping = 1;
        }
    }

    fclose(drm);
    fclose(std);

    return 0;
}