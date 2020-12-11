// Problem Statement:  https://practice.geeksforgeeks.org/contest-problem/binary-numbers5602/0/

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        string s;
        int cnt = 0, ok = 0;
        int res = 0;

        cin >> s;

        for (auto it : s)
        {
            if (it == '1')
            {
                cnt++;
                if (ok)
                    ok--;
            }
            else
            {
                if (cnt)
                {
                    res = max(res, cnt + ok);
                    ok++;
                }
            }
        }
        printf("%d\n", res);
    }
}
