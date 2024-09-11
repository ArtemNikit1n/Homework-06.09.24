#include <stdio.h>


void NullElements()
{
    // Задача 1

    printf("%s\n", "Enter the array size (<= 100):");

    const int lengthArrayNumbers;
    scanf_s("%d", &lengthArrayNumbers);

    if (lengthArrayNumbers > 100) {
        printf("%s\n", "The array size exceeds the allowed limit.");
        return 1;
    }

    printf("%s\n", "Enter the numbers of the array:");

    int arrayNumbers[100];
    int nullCounter = 0;

    for (int i = 0; i < lengthArrayNumbers; ++i) {
        scanf_s("%d", &arrayNumbers[i]);
        if (arrayNumbers[i] == 0) nullCounter += 1;
    }

    printf("%d\n", nullCounter);
}

void Swap() 
{
    // Задача 2

    int first = 0;
    int second = 0;

    int* left = &first;
    int* right = &second;

    printf("%s\n", "Enter first number:");
    scanf_s("%d", &first);

    printf("%s\n", "Enter second number:");
    scanf_s("%d", &second);

    *left ^= *right;
    *right ^= *left;
    *left ^= *right;

    printf("First number: %d ; Second number: %d", first, second);
}



void IncompleteQuotient()
{
    // Задача 3

    int a = 0;
    int b = 0;
    int answer = 0;

    printf("%s\n", "Enter a: ");
    scanf_s("%d", &a);

    printf("%s\n", "Enter b:");
    scanf_s("%d", &b);

    if (b != 0) {
        if (a >= 0 && b > 0) {
            while (a >= b) {
                a -= b;
                answer += 1;
            }
        }
        if (a < 0 && b > 0) {
            answer -= 1;
            while (a <= -b) {
                a += b;
                answer -= 1;
            }
            if (a == 0)
                answer += 1;
        }
        if (a > 0 && b < 0) {
            while (a >= -b) {
                a += b;
                answer -= 1;
            }
        }
        if (a < 0 && b < 0) {
            answer += 1;
            while (a <= b) {
                a -= b;
                answer += 1;
            }
            if (a == 0)
                answer -= 1;
        }
    }
    else
        printf("%s\n", "You can't divide by zero!");

    printf("Answer: %d", answer);
}

int main(void)
{
    int taskNumber = -1;

    printf("%s\n", "Enter task number:");
    scanf_s("%d", &taskNumber);

    if (taskNumber == 1)  NullElements();
    if (taskNumber == 2)  Swap();
    if (taskNumber == 3)  IncompleteQuotient();
}
