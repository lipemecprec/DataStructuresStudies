#include <stdio.h>

int list[100010], aux[100010];

int arraySize;

void mergeSort(int left, int right)
{

    if (left == right)
        return;

    int mid = (left + right) / 2;

    mergeSort(left, mid);
    mergeSort(mid + 1, right);

    int mergeIndex = left;
    int leftIndex = left, rightIndex = mid + 1;

    while (leftIndex <= mid && rightIndex <= right)
    {
        if (list[leftIndex] < list[rightIndex])
            aux[mergeIndex++] = list[leftIndex++]; // add from left list to aux
        else
            aux[mergeIndex++] = list[rightIndex++]; // add from right list to aux
    }
    while (leftIndex <= mid)
        aux[mergeIndex++] = list[leftIndex++]; // add from left list to aux

    while (rightIndex <= right)
        aux[mergeIndex++] = list[rightIndex++]; // add from right list to aux

    for (int i = left; i <= right; i++)
    {
        list[i] = aux[i];
    }
}

int main()
{

    // Read user input array
    int i = 0;
    for (i = 0; i < 100010; i++)
    {
        scanf("%d ", &list[i]);
        if (list[i] == 0)
            break;
    }

    int arraySize = i;

    mergeSort(0, arraySize);

    // Print out sorted data
    for (i = 1; i < arraySize + 1; i++)
    {
        printf("%d ", list[i]);
    }
}