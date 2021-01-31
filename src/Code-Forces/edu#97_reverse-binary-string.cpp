// Problem Statement: https://codeforces.com/contest/1437/problem/B

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
/*
2 2 4 4 4 5
1 2 3 4 5 6
1 0 1 0 1 1
*/
void test()
{
    int n;
    string s;
    cin >> n >> s;

    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1] and s[i] == '1')
            cnt1++;
        if (s[i] == s[i - 1] and s[i] == '0')
            cnt2++;
    }
    cout << max(cnt1, cnt2) << endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        test();
    return 0;
}
