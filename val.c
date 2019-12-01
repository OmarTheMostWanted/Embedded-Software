#include <stdlib.h>
# include <string.h>
#include <stdint.h>
#include <stdio.h>

int *alocatememory();

int *alocatememory1();

void uninitializeddata();

void stringstuff();

uint16_t returnNumber(uint16_t n);


int main() {

    uint16_t n = 5;
    printf("%d" , returnNumber(n));

    return 0;

}

uint16_t returnNumber(uint16_t n) {
    //uint8_t res = n + 1;
    return (n+1);
}

//int *alocatememory() {
//
//    int res[1000];
//
//    return res;
//
//}

int *alocatememory1() {

    int *res = (int *) malloc(sizeof(int) * 1000);

    return res;

}


void uninitializeddata() {
//    int i;
//
//    if (i == 102) //Conditional jump or move depends on uninitialised value(s)
//        i++;
}


void stringstuff() {

    char *course_name = " CSE2425 "; // " CSE2425 " + ’\0 ’

    char course_name_cpy1[8];
    strcpy(course_name_cpy1, course_name); //Invalid write of size

    char *course_name_cpy2 = malloc(sizeof(char) * 8);
    strcpy(course_name_cpy2, course_name);

    free(course_name_cpy2);

}