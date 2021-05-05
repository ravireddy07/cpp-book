// Problem Statement: https://leetcode.com/problems/implement-strstr/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        size_t index = -1;
        index = haystack.find(needle);
        return index;
    }
};

int main()
{
    Solution a;
    cout << a.strStr("hello", "ll") << "\n";
    return 0;
}
