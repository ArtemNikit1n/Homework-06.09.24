#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void NullElements()
{
    // Задача 1

    int lengthArrayNumbers = 0;
    int arrayNumbers[100];
    int nullCounter = 0;

    printf("%s\n", "Enter the array size (<= 100):");
    scanf("%d", &lengthArrayNumbers);
    printf("%s\n", "Enter the numbers of the array:");

    for (int i = 0; i <= lengthArrayNumbers; ++i) {
        scanf("%d", &arrayNumbers[i]);
        if (arrayNumbers[i] == 0) {
            nullCounter += 1;
        }
    }
    printf("Number of zeros = %d\n", nullCounter);
}

// ********

void Swap()
{
    // Задача 2

    int first = 0;
    int second = 0;

    printf("%s\n", "Enter first number:");
    scanf("%d", &first);

    printf("%s\n", "Enter second number:");
    scanf("%d", &second);

    first ^= second;
    second ^= first;
    first ^= second;

    printf("First number: %d ; Second number: %d", first, second);
}

// ********
int Division(const int a, const int b)
{
    int modulA = abs(a);
    int modulB = abs(b);
    int answer = 0;

    while (modulA >= modulB) {
        modulA -= modulB;
        answer += 1;
    }

    if (((a < 0 && b > 0) || (a < 0 && b < 0)) && modulA == 0) {
        answer -= 1;
    }
    return answer;
}

void IncompleteQuotient()
{
    // Задача 3

    int a = 0;
    int b = 0;
    int answer = 0;

    printf("%s\n", "Enter a: ");
    scanf("%d", &a);

    printf("%s\n", "Enter b:");
    scanf("%d", &b);

    if (b != 0) {
        if (a >= 0 && b > 0) {
            answer = Division(a, b);
        }
        if (a > 0 && b < 0) {
            answer = -Division(a, b);
        }
        if (a < 0 && b > 0) {
            answer = -Division(a, b);
            answer -= 1;
        }
        if (a < 0 && b < 0) {
            answer = Division(a, b);
            answer += 1;
        }
        printf("Answer: %d", answer);
    } else {
        printf("%s\n", "You can't divide by zero!");
    }
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

bool CheckingTheBalanceOfBrackets(const char string[])
{
    int balance = 0;

    for (int i = 0; i < 100; i++) {
        if (string[i] == '(') balance += 1;
        if (string[i] == ')') balance -= 1;
        else continue;
    }

    if (balance == 0) {
        return 1;
    } else {
        return 0;
    }
}

void BalanceOfBrackets()
{
    // Задача 5

    char string[100];

    printf("%s\n", "Enter a string with brackets:");
    scanf("%s", string);

    printf("Result: %d \n1 - means the brackets balance is satisfied"
           "\n0 - means it is not satisfied", CheckingTheBalanceOfBrackets(string));
}

// ********

bool IsItPrime(int number)
{
    int div = 2;
    while (div * div <= number) {
        if (number % div == 0)
            return 0;
        div += 1;
    }
    return 1;
}

void PrimeNumbers()
{
    // Задача 6

    int number = 0;

    printf("%s\n", "Enter number:");
    scanf("%d", &number);

    for (int i = 2; i <= number; i++) {
        if (IsItPrime(i)) {
            printf("%d ", i);
        }
    }
}

// ********

void Substring()
{
    // Задача 7

    char s[100];
    char s1[100];
    int occurrenceCounter = 0;

    printf("%s\n", "Enter S (<100):");
    scanf("%s", s);

    printf("%s\n", "Enter S1 (<100):");
    scanf("%s", s1);

    int i = 0;
    int j = 0;

    while (s[i] != '\0') {
        if (s[i] == s1[0]) {
            bool symbolsAreEqual = 1;
            while (s1[j] != '\0') {
                if (s[i + j] != s1[j]) {
                    symbolsAreEqual = 0;
                    break;
                }
                ++j;
            }
            if (symbolsAreEqual) {
                ++occurrenceCounter;
            }
        }
        ++i;
    }
    printf("Number of occurrences of the substring: %d", occurrenceCounter);
}

// ********

int main(void)
{
    int taskNumber = -1;

    printf("%s\n", "Enter task number:");
    scanf("%d", &taskNumber);

    if (taskNumber == 1) {
        NullElements();
    }
    if (taskNumber == 2) {
        Swap();
    }
    if (taskNumber == 3) {
        IncompleteQuotient();
    }
    if (taskNumber == 4) {
        LuckyTickets();
    }
    if (taskNumber == 5) {
        BalanceOfBrackets();
    }
    if (taskNumber == 6) {
        PrimeNumbers();
    }
    if (taskNumber == 7) {
        Substring();
    }
    if (taskNumber == 8) {
        printf("%s\n", "Not ready");
    }
}
