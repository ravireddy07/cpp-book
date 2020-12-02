// Problem Statement:  https://leetcode.com/problems/excel-sheet-column-number/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int titleToNumber(string s)
    {
        int result = 0, comb = s.size();
        for (int i = comb - 1; i >= 0; i--)
            result += pow(26, comb - i - 1) * ((int)s[i] - 64);
        return result;
    }
};

int main()
{
    Solution a;
    cout << a.titleToNumber("AX") << endl;
    return 0;
}
