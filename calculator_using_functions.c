#include <stdio.h>

float calculate(float a, float b, char op);

int main() {
    float num1, num2, result;
    char op;

    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Enter second number: ");
    scanf("%f", &num2);

    result = calculate(num1, num2, op);

    // Check if result is an integer value
    if ((int)result == result) {
        printf("Result = %d\n", (int)result);
    } else {
        printf("Result = %.2f\n", result);
    }

    return 0;
}

float calculate(float a, float b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                printf("Error: Division by zero!\n");
                return 0;
            }
            return a / b;
        default:
            printf("Invalid operator!\n");
            return 0;
    }
}

