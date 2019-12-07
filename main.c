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

    Grade *new_grade = (Grade *) malloc(sizeof(Grade));

    new_grade->next = next;

    for (int i = 0; i < 8; i++) {
        (*new_grade).name[i] = name[i];
    }

    new_grade->grade = grade;

    return new_grade;
}

//store_grades(int n, char *name, float grades[]) {
Grade *store_grades(int n, char names[][8], float grades[]) {

    Grade *next = 0;

    for (int i = 0; i < n; i++) {
        next = create_grade(next, names[i], grades[i]);
    }

    return next;
}

//Grade *store_grades(int n, char names[][8], float grades[]) {
//
//    char copy[8];
//    for(int i = 0 ; i < 8 ; i++)
//        copy[i] = names[0][i];
//
//    Grade* current = create_grade(NULL , copy , grades[n]);
//
//    n--;
//
//
//    while (n > 0) {
//
//        char temp[8];
//
//        for(int q = 0 ; q < 8 ; q++)
//            temp[q] = names[n][q];
//
//        Grade* new_Grade = create_grade( current , temp , grades[n]);
//        n--;
//
//        current->next = new_Grade;
//
//        current = new_Grade;
//    }
//
//    return current;
//}



void remove_grades(Grade *root) {

    Grade *current = root;

    while (current != 0) {

        Grade *current1 = current->next;

        free(current);

        current = current1;
    }
}

int size(Grade *grade) {
    Grade *current = grade;
    int n = 0;
    while (current != 0) {
        current = current->next;
        n++;
    }
    return n;
}


Grade *reverse_list1(Grade *grade) {


    Grade *res = NULL;
    while (grade) {
        Grade *next = grade->next;
        grade->next = res;
        res = grade;
        grade = next;
    }

    return res;


}

// defining a funtion pointer type called "rev" that returns grade and takes some para
typedef Grade *(*rev)(Grade *grade);


// the complier knows that this implements rev, because it have the same return type and paramters
Grade *reverse_list(Grade *grade) {


    const int s = size(grade);
    int count = 0;
    char names[s][8];

    float grades[s];

    Grade *current = grade;

    while (count < s) {

        for (int i = 0; i < 8; i++) {

            names[count][i] = current->name[i];

        }
        grades[count] = current->grade;

        current = current->next;

        count++;

    }

    return (store_grades(s, names, grades));

}

void printList(Grade *root) {

    int s = size(root);

    if (s == 0 || root == 0) {
        printf("Array is has the same number of elements as the number of fucks I give\n");
    }


    Grade *current = root;

    for (int i = 0; i < s; i++) {
        printf("%s , %f \n", current->name, current->grade);
        current = current->next;
    }

}


uint64_t *interrupt_vector;

void register_isr(uint8_t interrupt_source, void (*isr)()) {

    interrupt_vector[interrupt_source] = (uint64_t) isr;


}


void execute_isr(uint8_t interrupt_source) {

    void (*function)() = (void (*)()) interrupt_vector[interrupt_source];

    function();

}


// takes a funtion pointer
void foo(Grade *(*bar)()) {
    //..
}

//
void foo2(rev bar);

#include "hashmap.h"

void *resolve_collision(void *old_value, void *new_value) {
    return new_value;
}


int main() {

    unsigned int key_space = 1024;

    HashMap *hm = create_hashmap(key_space);

    char *string_1 = "CSE2425";
    char *string_2 = "Embedded";

    const char *key_1 = "ab";
    const char *key_2 = "cd";


    // Insert ("ab" -> "CSE2425").
    insert_data(hm, key_1, string_1, resolve_collision);

    unsigned int i = (hm->size % hash(key_1));


    Bucket *b = hm->bucket[i];

    insert_data(hm, key_1, string_2, resolve_collision);
    Bucket *c = hm->bucket[i];

    insert_data(hm, key_2, string_2, resolve_collision);


    return 0;
}