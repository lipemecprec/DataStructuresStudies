#include <stdio.h>

int N, Q, pos, attempt;
long long int ai[100010], tbf[500010];
int find(long long int tbf, int l, int size);

int main()
{
    scanf(" %d %d ", &N, &Q);

    for (int i = 1; i < N + 1; i++)
    {
        scanf("%lld ", &ai[i]);
    }

    for (int i = 1; i < Q + 1; i++)
    {
        scanf("%lld ", &tbf[i]);
    }

    for (int i = 1; i < Q + 1; i++)
    {
        find(tbf[i], 1, N);
        printf("\n");
    }
}

int find(long long int tbf, int l, int r)
{

    if (ai[l] == tbf)
        pos = l;
    else
        pos = -1;
    attempt++;
    int mid = (r + l) / 2;
    if (ai[mid] >= tbf)
    {
        l = mid;
        find(tbf, l, r);
    }
    else
    {
        r = mid;
        find(tbf, l, r);
    }
    return pos;
}