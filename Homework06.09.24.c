#include <stdio.h>


void NullElements()
{
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


int main(void)
{
    printf("%s\n", "Enter task number:");
    const int taskNumber = scanf_s("%d", &taskNumber);

    if (taskNumber == 1)  NullElements();
 
}
