#include <stdio.h>
    #include <stdint.h>


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


void ex() {

    char str;

    char s[4];


}


int main() {


}