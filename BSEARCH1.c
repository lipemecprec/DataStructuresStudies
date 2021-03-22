// https://www.spoj.com/problems/BSEARCH1/
// On going

#include <stdio.h>

int N, Q; // First line contains N Q, number of elements in the array and number of queries to follow,
// For each element in the query, print the elements 0 based location of its first occurence, if present, otherwise print -1.

long long int ai[100010], tbf[500010]; // Second line contains N numbers, elements of the array, each number will be -10^9<= ai <= 10^9, 0 < N <= 10^5, 0 < Q <= 5*10^5

int find(long long tbf, int l, int size);

int main()
{
    scanf("%d %d ", &N, &Q);

    for (int i = 0; i < N; i++)
    {
        scanf("%lld ", &ai[i]);
    }

    for (int i = 0; i < Q; i++)
    {
        scanf("%lld ", &tbf[i]);
    }

    for (int i = 0; i < Q; i++)
    {
        int g = find(tbf[i], 0, N);
        printf("%d\n", g);
    }
}

int find(long long int tbf, int ground, int heaven)
{
    int universe = heaven;
    int answer = -1;
    while (ground >= 0 && heaven <= universe && ground <= heaven)
    {
        int guess = (ground + heaven) / 2;
        // printf("ai[%d]: %d \t tbf: %d \tground: %d \theaven: %d\n", guess, ai[guess],  tbf, ground, heaven);
        if (ai[guess] == tbf)
        {
            answer = guess;
        }
        if (ai[guess] >= tbf)
        {
            heaven = guess - 1;
        }
        else
        {
            ground = guess + 1;
        }
    }
    return answer;
}