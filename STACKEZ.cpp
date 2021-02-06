// https://www.spoj.com/problems/STACKEZ/
// On going

#include <stdio.h>

const int VMAX = 1000010;

struct STACKEZ
{
    int p;
    int v[VMAX];

    STACKEZ()
    {
        p = 0;
    }

    void push(int value) { v[p++] = value; }

    bool empty() { return (p == 0); }

    void pop()
    {
        if (!this->empty())
            p--;
    }

    int top() { return v[p - 1]; }
};

STACKEZ s;

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++)
    {
        int type;
        scanf("%d", &type);
        {
            if (type == 1)
            {
                int value;
                scanf("%d", &value);

                s.push(value);
            }
            if (type == 2)
            {
                s.pop();
            }
            if (type == 3)
            {
                if (s.empty())
                    printf("Empty!\n");
                else
                    printf("%d\n", s.top());
            }
        }
    }
}
