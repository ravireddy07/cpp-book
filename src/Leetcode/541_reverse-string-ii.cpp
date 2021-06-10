// Problem Statement: https://leetcode.com/problems/reverse-string-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseStr(string s, int k)
    {
        string st = "", temp;
        int sp = 0, z = 1;
        while (sp < s.length())
        {
            temp = s.substr(sp, k);
            if (z)
            {
                reverse(temp.begin(), temp.end());
                z = 0;
            }
            else
                z = 1;
            sp += k;
            st = st + temp;
        }
        return st;
    }
};

int main()
{
    Solution a;
    cout << a.reverseStr("abcdefg", 2) << "\n";
    return 0;
}
