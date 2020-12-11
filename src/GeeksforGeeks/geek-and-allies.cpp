// Problem Statement:  https://practice.geeksforgeeks.org/contest-problem/geek-and-allies/0/

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void test(string &s, string temp, ll &res)
{
    if (temp.size() > s.size())
        return;

    if (temp.size() != 0 && temp.size() < s.size())
        res++;

    if (temp.size() != 0 && temp.size() == s.size())
        if (temp <= s)
            res++;

    if (temp.size() == 0)
    {
        for (int i = 1; i <= 9; ++i)
        {
            char c = i + '0';
            temp.push_back(c);
            test(s, temp, res);
            temp.pop_back();
        }
    }
    else
    {
        int num = temp[temp.size() - 1] - '0';
        for (int i = num; i <= 9; ++i)
        {
            char c = i + '0';
            temp.push_back(c);
            test(s, temp, res);
            temp.pop_back();
        }
    }
    return;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        string s, temp = "";
        cin >> s;
        ll res = 0;
        test(s, temp, res);
        printf("%lld\n", res);
    }
    return 0;
}
