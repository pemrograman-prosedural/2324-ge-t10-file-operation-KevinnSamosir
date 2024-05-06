#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dorm.h"
#include "student.h"

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender)
{
    struct dorm_t temp;
    memset(temp.name,"\0", sizeof(temp.name));
    strcpy(temp.name, _name);
    temp.capacity = _capacity;
    temp.residents_num = 0;
    temp.gender = _gender

    return temp;
    
};

void printAllDorms(struct dorm_t *dorm, int banyak_dorm) {
    for (int i = 0; i < banyak_dorm; i++) {
        if (dorm[i].gender != 1) {
            printf("%s|%d|male\n", dorm[i].name, dorm[i].capacity);
        } else {
            printf("%s|%d|female\n", dorm[i].name, dorm[i].capacity);
        }
    }
}

void printAllDormDetails(struct dorm_t *dorm, int banyak_dorm) {
    for (int i = 0; i < banyak_dorm; i++) {
        if (dorm[i].gender != 1) {
            printf("%s|%d|male|%d\n", dorm[i].name, dorm[i].capacity, dorm[i].residents_num);
        } else {
            printf("%s|%d|female|%d\n", dorm[i].name, dorm[i].capacity, dorm[i].residents_num);
        }
    }
}

void Newdorm(struct dorm_t *dorm, struct dorm_t *dorm_modif, int bamyak_dorm ){
     for (int i = 0; i < banyak_dorm; i++) {
        strcpy (dorm_modif[i].name, dorm[i].name)
        dorm_modif[i].gender = dorm [i].gender;
        dorm_modif [i].capacity = dorm [i].capacity;
        dorm_modif [i].residents_num = dorm [i].residentrs_num;
     }
}