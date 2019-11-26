#include <stdio.h>
#include <stdlib.h>


long *makeLongArray() {

    long *test = (long *) malloc(sizeof(long) * 10);

    //long *test1 = (long*) malloc(sizeof(int*));


    for (int i = 0; i < 11; i++) {

        *(test + i) = i;
    }

    //*test1 = 32;
    return test;

}

char *charpointer() {

    char *res = malloc(1);

    *res = 'h';

    return res;
}

void *mallocling() {

    void *e = malloc(sizeof(int *));
    void *d = malloc(2);

    printf("%d \n", e);
    printf("%d", e + 1);
    printf("\n %d \n", e + 2);


    printf("%d \n", d);
    printf("%d", d + 1);


}

//one way to init a 2d array {the manual way}
char *make2darray1() {
    int r = 3, c = 4;
    char *arr = (char *) malloc(r * c * sizeof(char));

    int i, j, count = 0;

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            *(arr + i * c + j) = ++count; // do stuff and arr[r][c]
        }

    return arr;
}

//way to make an 2d array
char *make2darray2() {

    int r = 3, c = 4, i, j, count;

    char *arr = (char *) malloc(sizeof(char *) * r);

    for (i = 0; i < r; i++)
        *(arr + i) = (char *) malloc(c * sizeof(char));

    // Note that arr[i][j] is same as *(*(arr+i)+j)
    count = 0;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            *((arr + i) + j) = ++count; // Or *(*(arr+i)+j) = ++count

    return arr;
}


int main() {


    char *arr = make2darray2();

    for (int i = 0; i < 13; i++) {
        printf("%d \n", *(arr + i));
    }


    return 0;

}