#include <bits/stdc++.h>
#define lli long long int
using namespace std;

void test()
{
    int x, y;
    scanf("%d%d", &x, &y);
    if (x == y)
        printf("%d\n", x + y);
    else
        printf("%d\n", x + y + abs(x - y) - 1);
}

// Brute Force
void test()
{
    int x, y;
    scanf("%d%d", &x, &y);
    if (x == y)
    {
        printf("%d\n", x + y);
        return;
    }

    int res = 0;
    bool turn = 0;
    if (abs(x) > abs(y))
        turn = 1;

    while (1)
    {
        if (x == 0 && y == 0)
            break;

        if (x > 0 and turn)
        {
            res++;
            x--;
        }
        else if (x < 0 and turn)
        {
            res++;
            x--;
        }
        else if (0 == x and turn)
            res++;

        if (y > 0 and !turn)
        {
            res++;
            y--;
        }
        else if (y < 0 and !turn)
        {
            res++;
            y--;
        }
        else if (0 == y and !turn)
            res++;

        turn = turn ? 0 : 1;
    }
    printf("%d\n", res);
    return;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        test();
    return 0;
}
