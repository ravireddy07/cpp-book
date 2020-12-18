// Problem Statement:  https://leetcode.com/problems/reverse-only-letters/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Optimal Solution
    string reverseOnlyLetters(string S)
    {
        for (int i = 0, j = S.length() - 1; i < j;)
        {
            if (!isalpha(S[i]))
                ++i;
            else if (!isalpha(S[j]))
                --j;
            else
                swap(S[i++], S[j--]);
        }
        return S;
    }

    string reverseOnlyLetters(string s)
    {
        string planeText = "";
        for (int i = 0; i < s.size(); i++)
            if (s[i] >= 'a' and s[i] <= 'z' || s[i] >= 'A' and s[i] <= 'Z')
                planeText += s[i];
        reverse(planeText.begin(), planeText.end());

        string res = "";
        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'a' and s[i] <= 'z' || s[i] >= 'A' and s[i] <= 'Z')
            {
                res += planeText[j];
                j++;
            }
            else
                res += s[i];
        }
        return res;
    }
};

int main()
{
    Solution a;
    cout << a.reverseOnlyLetters("a-bC-dEf-ghIj") << endl;
    return 0;
}
