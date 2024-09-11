#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS


void NullElements()
{
    printf("%s\n", "Enter the numbers of the array");

    int arrayNumbers[6];
    int lengthArrayNumbers = sizeof(arrayNumbers) / sizeof(arrayNumbers[0]);
    int nullCounter = 0;
    int additionIndex = 0;

    for (int i = 0; i < 5; ++i) {
        arrayNumbers[additionIndex] = scanf_s("%d", &arrayNumbers[additionIndex]);
    }

    for (int i = 0; i < lengthArrayNumbers; i++)
    {
        if (arrayNumbers[i] == 0) nullCounter += 1;
    }

    printf("%d\n", nullCounter);
}


int main(void)
{
    printf("%s\n", "Enter task number:");
    int taskNumber = scanf_s("%d", &taskNumber);

    if (taskNumber == 1)  NullElements();
 
}
