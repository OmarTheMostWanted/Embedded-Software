#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "main.h"


#define tes 1
#define check(x) (x == tes)


int give_number() {
    return 42;
}

int add(int a, int b) {

    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

int modulo(int a, int b) {
    return a % b;
}

int is_even(int n) {
    if (n % 2 == 0)
        return 1;

    else return 0;
}

int absolute(int n) {
    if (n >= 0)
        return n;

    else return -n;
}

int alternating_sum(int n) {
    int res = 0;


    for (int i = 0; i <= n; i++) {

        if (is_even(i))
            res += i;
        else res -= i;

    }
    return res;
}

//int inner_product_helper(int *a, int *b, int len);


int inner_product_helper(int *a, int *b, int len) {

    int res = 0;


    for (int i = 0; i < len; i++) {
        res += *(a + i) * *(b + i);
    }

    return res;

}

int inner_product(int *a, int a_len, int *b, int b_len) {


    if (a_len <= b_len) {
        return (inner_product_helper(a, b, a_len));

    } else return (inner_product_helper(a, b, b_len));

}

int make_odd_negative(int *a, int size) {

    int res = 0;

    for (int i = 0; i < size; i++) {

        if (is_even(*(a + i)) == 0 && *(a + i) > 0) {
            *(a + i) *= -1;
            res++;
        }
    }

    return res;

}

int make_even_positive(int *a, int size) {

    int res = 0;

    for (int i = 0; i < size; i++) {
        if (is_even(*(a + i)) == 1 && *(a + i) < 0) {
            *(a + i) *= -1;
            res++;
        }
    }

    return res;

}

int mangle_array(int *a, int size) {
    return make_even_positive(a, size) + make_odd_negative(a, size);
}

uint8_t set_bit(uint8_t reg, int n) {
    uint8_t mask = 1;

    mask = mask << n;

    return mask | reg;
}


uint8_t unset_bit(uint8_t reg, int n) {
    uint8_t mask = 1;
    mask = mask << n;

    mask = ~mask;

    printBits(mask);
    printf("\n");

    return (mask & reg);

}

int is_set(uint8_t reg, int n) {


    uint8_t mask = 1;
    mask = mask << n;

    if ((mask & reg) == 0) {
        return 0;
    } else return 1;

}

void get_knob_positions(uint8_t knobs, uint8_t *knob1_position, uint8_t *knod2_position) {
    *knob1_position = knobs & 0b00001111;
    *knod2_position = knobs >> 4;
}

void printBits(uint8_t num) {

    for (int bit = 0; bit < (sizeof(uint8_t) * 8); bit++) {
        printf("%i ", num & 0x01);
        num = num >> 1;
    }
}


typedef struct Grade {
    struct Grade *next;
//    char *name; why does this not work??? should it not be the same as the name[8]
    char name[8];
    float grade;
} Grade;

Grade *create_grade(Grade *next, char *name, float grade) {

    Grade *new_grade = (Grade *) malloc(sizeof(Grade *));

    new_grade->next = next;

    for (int i = 0; i < 8; i++) {
        (*new_grade).name[i] = name[i];
    }

    new_grade->grade = grade;

    return new_grade;
}

//store_grades(int n, char *name[8], float grades[]) {
store_grades(int n, char name[n][8], float grades[]) {

}

int main() {

    return 0;
}