// https://leetcode.com/problems/longest-uncommon-subsequence-i/

#include <iostream>
using namespace std;

class Solution
{
public:
    int findLUSlength(string a, string b)
    {
        if (a.size() > b.size())
            return a.size();
        if (a.size() < b.size())
            return b.size();
        if (a == b)
            return -1;
        return a.size();
    }
};

int main()
{
    Solution a;
    cout << a.findLUSlength("aba", "cdc") << endl;
    return 0;
}