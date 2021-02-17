// https://olimpiada.ic.unicamp.br/pratique/p1/2010/f2/danca/
// On Going

#include <iostream>
#include <stdbool.h>

using namespace std;

int v[1010] = {}, d[1010] = {};

void mergeSort(int l, int r);
int list[1010], aux[1010];

int main()
{
    int N, E, turn = 0; // N Toras, E índios
    int ref[1010] = {}; // vetores para as posições, direções e vetor auxiliar
    bool gameOver = false;
    scanf("%d %d ", &N, &E);
    for (int i = 0; i < E ; i++)
    {
        scanf("%d %d ", &v[i], &d[i]); // v[i][0] - position / v[i][1] - direction
        ref[i] = v[i]; // set reference for gameOver
    }
    end[N][E] = {};
    for (int i = 0; i < E ; i++) // Make possible end conditions
    {
        for ( int j = 0 ; j < E ; j++ ){
            if ( v[i] < ref[j])
                end[i][j] = ref[j] ; 
        }
    }

    


    printf("%d", turn);
}

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
        if (list[leftIndex][0] < list[rightIndex][0])
            aux[mergeIndex++] = list[leftIndex++][0]; // add from left list to aux
        else
            aux[mergeIndex++] = list[rightIndex++][0]; // add from right list to aux
    }
    while (leftIndex <= mid)
        aux[mergeIndex++] = list[leftIndex++][0]; // add from left list to aux

    while (rightIndex <= right)
        aux[mergeIndex++] = list[rightIndex++][0]; // add from right list to aux

    for (int i = 0; i <= right; i++)
    {
        list[i][0] = aux[i];
    }
}