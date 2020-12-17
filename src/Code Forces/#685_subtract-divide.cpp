#include <bits/stdc++.h>
#define lli long long int
using namespace std;

void test()
{
    lli n;
    scanf("%lld", &n);
    if (n == 1)
        cout << 0 << endl;
    else if (n == 2)
        cout << 1 << endl;
    else if (n % 2 == 0 or n == 3)
        cout << 2 << endl;
    else
        cout << 3 << endl;
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
