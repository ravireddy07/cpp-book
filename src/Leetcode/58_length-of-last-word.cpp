// https://leetcode.com/problems/length-of-last-word/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        string s2;
        for (int i = s.length() - 1; i >= 0; --i)
        {
            if (s2.length() > 0 && s[i] == ' ')
                break;
            else if (s[i] != ' ')
                s2 += s[i];
        }
        return s2.length();
    }
};

int main()
{
    Solution a;
    cout << a.lengthOfLastWord("gya jeq qq   ") << endl;
    return 0;
}