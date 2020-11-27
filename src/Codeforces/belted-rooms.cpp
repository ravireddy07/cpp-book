// https://codeforces.com/contest/1428/problem/B

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int nax = 1e6 + 5;
char s[nax];

void test()
{
    int n;
    cin >> n >> s;
    bool one = 1, two = 1;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '>')
            one = 0;
        if (s[i] == '<')
            two = 0;
    }

    if (one || two)
        cout << n << endl;
    else
    {
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '-' || s[(i + 1) % n] == '-')
                cnt++;
        }
        cout << cnt << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        test();
    return 0;
}