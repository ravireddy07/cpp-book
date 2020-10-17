// https://codeforces.com/contest/1428/problem/C

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void test()
{
    string s;
    cin >> s;
    string res = "";
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (!res.empty() && res.back() == 'A' && s[i] == 'B')
            res.pop_back();
        else if (!res.empty() && res.back() == 'B' && s[i] == 'B')
            res.pop_back();
        else
            res += ch;
    }
    cout << res.length() << endl;
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