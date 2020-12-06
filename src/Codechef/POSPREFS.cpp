// Problem Statement: https://www.codechef.com/DEC20B/problems/POSPREFS

#include <bits/stdc++.h>
using namespace std;

//        Understanding:
//        Logic:          Sequence must have k Positive Integers & (n-k) Negative Integers.

/*
Example Test Cases:

5 1
-1 2 -3 -4 -5

10 6
-1 2 -3 4 -5 6 -7 8 9 10

*/

void test()
{
    int n, k;
    scanf("%d%d", &n, &k);

    int shift = 1;
    int neg = abs(n - k), pos = k;

    for (int i = 1; i <= n; ++i)
    {
        if (pos == 0)
            printf("%d ", -i);
        else if (neg == 0)
            printf("%d ", i);
        else if (shift)
        {
            printf("%d ", -i);
            shift = shift ? 0 : 1;
            neg--;
        }
        else
        {
            printf("%d ", i);
            shift = shift ? 0 : 1;
            pos--;
        }
    }
    printf("\n");
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
