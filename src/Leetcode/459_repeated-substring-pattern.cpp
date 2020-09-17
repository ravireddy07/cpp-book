// https://leetcode.com/problems/repeated-substring-pattern/

#include <iostream>
using namespace std;

/*
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        return (s + s).substr(1, 2 * s.size() - 2).find(s) != -1;
    }
};
*/

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.length();
        vector<int> dp(n, 0);
        int j = 0;
        for (int i = 1; i < n;)
        {
            if (s[i] == s[j])
            {
                j++;
                dp[i] = j;
                i++;
            }
            else
            {
                if (j != 0)
                {
                    j = dp[j - 1];
                }
                else
                {
                    dp[i] = 0;
                    i++;
                }
            }
        }
        return dp[n - 1] && (dp[n - 1] % (n - dp[n - 1]) == 0);
    }
};

int main()
{
    Solution a;
    cout << a.repeatedSubstringPattern("abcabcabcabc") << endl;
}