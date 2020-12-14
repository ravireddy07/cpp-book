// Problem Statement: https://www.codechef.com/DEC20B/problems/VACCINE1

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void test()
{
    int d1, d2, v1, v2, p;
    scanf("%d %d %d %d %d", &d1, &v1, &d2, &v2, &p);
    int days = 1, vacc = 0;
    while (p > vacc)
    {
        if (days >= d1)
            vacc += v1;
        if (days >= d2)
            vacc += v2;
        days++;
    }
    printf("%d\n", days - 1);
    return;
}

int main()
{
    /*int t;
    scanf("%d", &t);
    while (t--)*/
    test();
    return 0;
}
