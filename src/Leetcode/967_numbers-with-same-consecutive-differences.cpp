// Problem Statement: https://leetcode.com/problems/numbers-with-same-consecutive-differences/

#include <bits/stdc++.h>
using namespace std;

int mod(int a)
{
    return a >= 0 ? a : -1 * a;
}

class Solution
{
public:
    vector<int> v;
    void help(int n, int k, int s, int N, int prev)
    {
        //n-numDigits
        if (n == N)
        {
            v.push_back(s);
            return;
        }
        for (int i = 0; i <= 9; i++)
            if (mod(prev - i) == k)
                help(n + 1, k, s * 10 + i, N, i);
    }

    void fun(int k, int n)
    {
        for (int i = 1; i <= 9; i++)
            help(1, k, i, n, i);
    }

    vector<int> numsSameConsecDiff(int n, int k)
    {
        if (n == 1)
        {
            for (int i = 0; i <= 9; i++)
                v.push_back(i);
            return v;
        }
        int s = 0;
        fun(k, n);
        return v;
    }
};

int main()
{
    Solution a;
    vector<int> show = a.numsSameConsecDiff(2, 3);
    cout << "[";
    for (int i = 0; i < show.size(); i++)
    {
        if (i == show.size() - 1)
            cout << show[i];
        else
            cout << show[i] << ", ";
    }
    cout << "]"
         << "\n";
    return 0;
}
