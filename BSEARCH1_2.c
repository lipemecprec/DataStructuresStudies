// BSEARCH1 - Binary search
// You are given a sorted array of numbers, and followed by number of queries,
// for each query if the queried number is present in the array print its position, else print -1.

// Input
// First line contains N Q, number of elements in the array and number of queries to follow,
// Second line contains N numbers, elements of the array, each number will be -10^9<= ai <= 10^9, 0 < N <= 10^5, 0 < Q <= 5*10^5

// Output
// For each element in the query, print the elements 0 based location of its first occurence, if present, otherwise print -1.

#include <stdio.h>
long long int search(long long int ai[], int N, long long int qv);

int main()
{
    long long int ai[5 * (10 ^ 5) + 10];
    int N, Q;

    scanf("%d %d", &N, &Q);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld ", &ai[i]);
    }
    long long int qv;
    for (int i = 0; i < Q; i++)
    {
        scanf("%lld ", &qv);
        printf("%lld\n", search(ai, N, qv));
    }
}

long long int search(long long int ai[], int N, long long int qv)
{
    long int l = 0, r = N, index;
    while (l >= 0 && r <= N && r >= l)
    {
        index = l + (r - l) / 2;
        if (ai[index] == qv)
            return index;
        else if (ai[index] < qv)
        {
            l = index + 1;
        }
        else
        {
            r = index - 1;
        }
    }
    return -1;
}