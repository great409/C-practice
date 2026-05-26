#include <stdio.h>

int main(void)
{
    float num1, num2;
    char operator;

    // Ask user for first number
    printf("Enter first number: ");
    scanf("%f", &num1);

    // Ask user for operator
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);

    // Ask user for second number
    printf("Enter second number: ");
    scanf("%f", &num2);

    // Perform calculation
    if (operator == '+')
    {
        printf("Result: %.2f\n", num1 + num2);
    }
    else if (operator == '-')
    {
        printf("Result: %.2f\n", num1 - num2);
    }
    else if (operator == '*')
    {
        printf("Result: %.2f\n", num1 * num2);
    }
    else if (operator == '/')
    {
        if (num2 != 0)
        {
            printf("Result: %.2f\n", num1 / num2);
        }
        else
        {
            printf("Error: Cannot divide by zero\n");
        }
    }
    else
    {
        printf("Invalid operator\n");
    }

    return 0;
}
