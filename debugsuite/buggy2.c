#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    printf("Calculator. \n");
    printf("Usage: <operand1> <operation> <operand2>\n");
    printf("Example: 2 + 5\n");

    //scanf does not like pointers
//	int *operand1;
//	int *operand2;
//	char *operation;


//fix: dont use pointers and give scanf adress using &
// better to init variables
    int operand1;
    int operand2;
    char operation;
    scanf("%d %c %d", &operand1, &operation, &operand2);


//	scanf("%d %c %d", operand1, operation, operand2);


    int result;

    //fix: dont use pointers and break from the loop in the cases
//	switch (*operation) {
//		case '+': result = *operand1 + *operand2;
//		case '-': result = *operand1 - *operand2;
//		case '*': result = *operand1 * *operand2;
//		case '/': result = *operand1 / *operand2;
//		default:
//			printf("Invalid operation\n");
//			break;
//	}


    switch (operation) {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;

        case '/':
            result = operand1 / operand2;
            break;

        default:
            printf("Invalid operation\n");
            break;
    }


    printf("> %d\n", result);

    return 0;
}
