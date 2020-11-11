#include <bits/stdc++.h>
using namespace std;

void fibDP(int n)
{
    if (n == 0 or n == 1)
        cout << n;
    int count = 2;
    int res = 1, a = 0, b = 1, nextB = 0;
    cout << 0 << " " << 1 << " ";
    while (count < n)
    {
        nextB = a + b;
        count++;
        a = b;
        b = nextB;
        res += nextB;
        cout << nextB << " ";
    }
}

int main()
{
    fibDP(8);
    return 0;
}
