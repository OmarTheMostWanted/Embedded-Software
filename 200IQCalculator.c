#include <stdio.h>

typedef int (*calc)(int a, int b);

int add(int a, int b) {
    return (a + b);
}


int sub(int a, int b) {
    return (a - b);
}

int mul(int a, int b) {
    return (a * b);
}

int div(int a, int b) {
    return (a / b);
}

//int calculate (calc fun200IQ , int a , int b) {
//    return fun200IQ(a , b);
//}


int calculate(calc math, int a, int b) {
    return math(a, b);
}

int fun200IQ() {
    int a, b;

    a = 0;
    b = 0;

    char c;

    c = 0;

    scanf("%d", &a);
    scanf("%c", &c);
    scanf("%d", &b);

    switch (c) {
        case '+':
            return calculate(add, a, b);

        case '-':
            return calculate(sub, a, b);

        case '*':
            return calculate(mul, a, b);

        case '/':
            return calculate(div, a, b);

        default:
            return 8734729;
    }

}


int main() {

    while (1) {

        int res = fun200IQ();

        if(res == 8734729)
            break;

        printf("%d", res);


    }
    return 0;
}