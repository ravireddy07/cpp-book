// Problem Statement: https://leetcode.com/contest/weekly-contest-205/problems/replace-all-s-to-avoid-consecutive-repeating-characters/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string modifyString(string s)
    {
        char temp1, temp2;
        int index;
        for (int k = 0; k < s.length(); ++k)
        {
            if (s[k] == '?')
            {
                index = k;
                for (int i = 0; i < 26; i++)
                {
                    if (index == 0)
                    {
                        if (s[k + 1] != (char)(96 + i))
                        {
                            s[k] = (char)(96 + i);
                            continue;
                        }
                    }
                    else if (index > 0 && index < s.length())
                    {
                        temp1 = s[k - 1];
                        temp2 = s[k + 1];
                        if (temp1 != (char)(96 + i) && temp2 != (char)(96 + i))
                        {
                            s[k] = (char)(96 + i);
                            continue;
                        }
                    }
                }
            }
        }
        return s;
    }
};

int main()
{
    Solution a;
    cout << a.modifyString("?ah") << "\n";
    return 0;
}
