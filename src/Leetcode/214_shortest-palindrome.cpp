// https://leetcode.com/problems/shortest-palindrome/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string shortestPalindrome(string s)
    {
        if (s.length() == 0)
            return s;
        string rev = s;
        reverse(rev.begin(), rev.end());
        string str = s + '#' + rev;
        int *prefix = new int[str.length()];

        int i = 1, len = 0;
        prefix[0] = 0;
        while (i < str.length())
        {
            if (str[i] == str[len])
            {
                len++;
                prefix[i] = len;
                i++;
            }
            else
            {
                if (len > 0)
                    len = prefix[len - 1];
                else
                {
                    prefix[i] = 0;
                    i++;
                }
            }
        }
        int pos = prefix[str.length() - 1];
        string add = s.substr(pos, s.length() - pos);
        reverse(add.begin(), add.end());
        delete[] prefix;
        return add + s;
    }
};

int main()
{
    Solution a;
    cout << a.shortestPalindrome("aacecaaa") << endl;
    return 0;
}