#include <stdio.h>
#include <math.h>

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

// ********

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

// ********

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

// ********

void LuckyTickets()
{
    // Задача 4

    int amounts[28] = {0};
    int answer = 0;

    for (int number = 0; number < 1000; number++) {
        int hundreds = number / 100;
        int units = number % 10;
        int tens = (number - (100 * hundreds) - units) / 10;
        int sum = hundreds + tens + units;

        amounts[sum] += 1;
    }

    for (int i = 0; i < 28; i++) {
        amounts[i] *= amounts[i];
        answer += amounts[i];
    }
    printf("%d", answer);
}

// ********

int prime(int num)
{
    for (int div = 2; div <= (int)ceil(sqrt(num)); div++) {
        if (num % div == 0)
            return 0;
    }
    return 1;
}

void PrimeNumbers()
{
    // Задача 6

    int num;
    printf("%s\n", "Enter number:");
    scanf_s("%d", &num);

    for (int i = 1; i <= num; i++) {
        if (prime(i) == 1) printf("%d ", i);
    }
}

// ********

int main(void)
{
    int taskNumber = -1;

    printf("%s\n", "Enter task number:");
    scanf_s("%d", &taskNumber);

    if (taskNumber == 1)  NullElements();
    if (taskNumber == 2)  Swap();
    if (taskNumber == 3)  IncompleteQuotient();
    if (taskNumber == 4)  LuckyTickets();
    if (taskNumber == 5)  printf("%s\n", "Not ready");
    if (taskNumber == 6)  PrimeNumbers();
    if (taskNumber == 7)  printf("%s\n", "Not ready");
    if (taskNumber == 8)  printf("%s\n", "Not ready");
}
