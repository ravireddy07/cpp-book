// Problem Statement: https://leetcode.com/problems/find-the-difference/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int sum = 0;
        for (int i = 0; i < s.size(); i++)
            sum += t[i] - s[i];
        return sum + t[t.size() - 1];
    }
};

int main()
{
    Solution a;
    cout << a.findTheDifference("abcd", "abcde") << "\n";
    return 0;
}
