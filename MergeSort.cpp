#include <stdio.h>

int swap (int a, int b){
    int swap;
   
    swap = a;
    a = b;
    b = swap;
}

void mergeSort(int* list[], int left, int right){
    
    int mid;
    
    if (left == right) return;
    
    mid = (left + right - 1 ) / 2;
    
    mergeSort(list, left , mid);
    mergeSort(list, mid + 1, right);
    
    int ArrSize = mid + 1;
    int leftArr[ArrSize], rightArr[ArrSize];
    
    // transfering data to temporary arrays
    for (int i = 0 ; i <= mid ; i++){
        leftArr[i] = list[left + i];
    }
    for (int i = 0 ; i <= right ; i++){
        rightArr[i] = list[mid + i];
    }
    printf("\n left Array");
    for (int i=0 ; i <= mid ; i++){
        printf("%d ", leftArr[i]);
    }
    printf("\n right Array");
    for (int i = 0 ; i <= right ; i++){
        printf("%d ", rightArr[i]);
    }
    
}

int main() {

    int list[100010];

    // Read user input array
    int i = 0;
    for (i = 0 ; i < 100010 ; i++){
        scanf("%d ", &list[i]);
        if(list[i]==0)break;
    }
    // printf("i = %d",i);
    int arraySize = i;
    // printf("ArraySize = %d",arraySize);
    // for (i=0;i<arraySize;i++){
    //     printf("Pos[%d]: %d | ", i, list[i]);
    // }
    
    mergeSort(list, 0 , arraySize - 1);
    
    for (i=0 ; i<arraySize ; i++){
        printf("%d ", list[i]);
    }

}# DataStructuresStudies
