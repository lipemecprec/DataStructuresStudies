// https://br.spoj.com/problems/ELEICOES/
#include <stdio.h>

int aux[1000010];
long long int boletim[1000010], v;
long long int winner = 0;

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
        if (boletim[leftIndex] > boletim[rightIndex])
        {
            aux[mergeIndex++] = boletim[leftIndex++]; // add from left list to aux
        }
        else
        {
            aux[mergeIndex++] = boletim[rightIndex++]; // add from right list to aux
        }
    }
    while (leftIndex <= mid)
    {
        aux[mergeIndex++] = boletim[leftIndex++]; // add from left list to aux
    }

    while (rightIndex <= right)
    {
        aux[mergeIndex++] = boletim[rightIndex++]; // add from right list to aux
    }

    for (int i = left; i <= right; i++)
    {
        boletim[i] = aux[i];
    }
}

int findWinner(int N)
{
    int ref, act, actCount, maxVotes = 0;
    for (int i = 1; i <= N;)
    {
        ref = act = i;
        actCount = 1;
        while (boletim[ref] == boletim[act] && act <= N)
        {
            actCount++;
            act++;
        }
        if (actCount > maxVotes)
        {
            maxVotes = actCount;
            winner = boletim[ref];
        }
        i = act;
    }
    return winner;
}

int main()
{
    int N; //votes qty

    scanf("%d ", &N);

    for (int i = 1; i <= N; i++)
    {
        scanf("%lld ", &boletim[i]);
    }

    mergeSort(1, N);

    // for (int i = 1; i <= N; i++)
    // {
    //     printf("%lld ", boletim[i]);
    // }
    findWinner(N);
    printf("%lld", winner);
}