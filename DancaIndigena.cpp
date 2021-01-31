// https://olimpiada.ic.unicamp.br/pratique/p1/2010/f2/danca/
// Solved

#include <iostream>
#include <stdbool.h>

using namespace std;

int v[1010][2] = {{}}, d[1010][2] = {{}};

void mergeSort(int l, int r);
int list[1010][1], aux[1010];

int main()
{
    int N, E, turn = 0;      // N Toros, E índios
    int ref[1010][2] = {{}}; // vetores para as posições, direções e vetor auxiliar
    bool gameOver = false;
    scanf("%d %d ", &N, &E);
    for (int i = 2; i < E + 2; i++)
    {
        scanf("%d %d ", &v[i][0], &v[i][1]); // v[i][0] - position / v[i][1] - direction
    }
    for (int i = 2; i < E + 2; i++) // set reference for gameOver
    {
        ref[i][0] = v[i][0];
    }

    while (gameOver == false)
    {
        // set circle
        v[0][0] = v[N - 1][0];
        v[0][1] = v[N - 1][1];
        v[1][0] = v[N][0];
        v[1][1] = v[N][1];
        v[N + 1][0] = v[2][0];
        v[N + 1][1] = v[2][1];
        v[N + 2][0] = v[3][0];
        v[N + 2][1] = v[3][1];
        turn++;
        // printf("---------------------------------------------------Turn %d\n", turn);
        for (int i = 2; i < E + 2; i++)
        {
            if (v[i][1] == 1 && v[i][0] == v[i + 1][0] - 1 && v[i + 1][1] == -1)
            {
                d[i][0] = v[i][0];  // no jump
                d[i][1] = -v[i][1]; // reverse direction
                // printf("No jump & reverse 1 - \tPv %d \t Dv %d \t-  Pd %d \t Dd %d\n", v[i][0], v[i][1], d[i][0], d[i][1]);
            }
            else if (v[i][1] == -1 && v[i][0] == v[i - 1][0] + 1 && v[i - 1][1] == 1)
            {
                d[i][0] = v[i][0];  // no jump
                d[i][1] = -v[i][1]; // reverse direction
                // printf("No jump & reverse 2 - \tPv %d \t Dv %d \t-  Pd %d \t Dd %d\n", v[i][0], v[i][1], d[i][0], d[i][1]);
            }
            else if (v[i][1] == 1 && v[i][0] == v[i + 1][0] - 2 && v[i + 1][1] == -1)
            {
                d[i][0] = v[i][0] + 1; // jump
                d[i][1] = -v[i][1];    // reverse direction
                // printf("No jump & reverse 3 - \tPv %d \t Dv %d \t-  Pd %d \t Dd %d\n", v[i][0], v[i][1], d[i][0], d[i][1]);
            }
            else if (v[i][1] == -1 && v[i][0] == v[i - 1][0] + 2 && v[i - 1][1] == 1)
            {
                d[i][0] = v[i][0] - 1; // jump
                d[i][1] = -v[i][1];    // reverse direction
                // printf("No jump & reverse 3 - \tPv %d \t Dv %d \t-  Pd %d \t Dd %d\n", v[i][0], v[i][1], d[i][0], d[i][1]);
            }
            else
            {
                d[i][0] = v[i][0] + v[i][1]; // jump
                d[i][1] = v[i][1];           // jump
                // printf("Jump \t\t\t\t- \tPv %d \t Dv %d \t-  Pd %d \t Dd %d\n", v[i][0], v[i][1], d[i][0], d[i][1]);
            }
        }
        for (int i = 2; i < E + 2; i++) // copy d to v
        {
            if (d[i][0] < 1)
            {
                d[i][0] = N + d[i][0];
            }
            else if (d[i][0] > N)
            {
                d[i][0] = d[i][0] - N;
            }
            for (int j = 0; j < 2; j++)
            {
                v[i][j] = d[i][j];
            }
        }
        gameOver = true;
        for (int i = 2; i < E + 2; i++) // set reference for gameOver
        {
            list[i][0] = v[i][0];
        }
        mergeSort(2, E + 1);
        for (int i = 0; i < E + 4; i++)
        { // Verifies end condition
            if (aux[i] != ref[i][0])
                gameOver = false;
            // printf("---------------------------------------------- Check \t\t\t\t- \tPref %d \t Dd %d \t\n", ref[i][0], aux[i]);
        }
        if (turn == 10)
            gameOver = true;
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