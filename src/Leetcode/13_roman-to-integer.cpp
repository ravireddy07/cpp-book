// Problem Statement: https://leetcode.com/problems/roman-to-integer/

// problem discussion: https://leetcode.com/problems/roman-to-integer/discuss/829390/C%2B%2B-Simple-4ms-Solution-or-Beats-99-Faster-Solution-or-O(n)-Complexity

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int sum = 0;
        if (s.length() == 0 || s == "")
            return 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'I')
            {
                if (s[i + 1] == 'V')
                {
                    sum += 4;
                    i++;
                }
                else if (s[i + 1] == 'X')
                {
                    sum += 9;
                    i++;
                }
                else
                    sum += 1;
            }
            else if (s[i] == 'X')
            {
                if (s[i + 1] == 'L')
                {
                    sum += 40;
                    i++;
                }
                else if (s[i + 1] == 'C')
                {
                    sum += 90;
                    i++;
                }
                else
                    sum += 10;
            }
            else if (s[i] == 'C')
            {
                if (s[i + 1] == 'D')
                {
                    sum += 400;
                    i++;
                }
                else if (s[i + 1] == 'M')
                {
                    sum += 900;
                    i++;
                }
                else
                    sum += 100;
            }
            else if (s[i] == 'V')
                sum += 5;
            else if (s[i] == 'L')
                sum += 50;
            else if (s[i] == 'D')
                sum += 500;
            else if (s[i] == 'M')
                sum += 1000;
        }
        return sum;
    }
};

int main()
{
    Solution a;
    cout << a.romanToInt("IV") << "\n";
    return 0;
}
