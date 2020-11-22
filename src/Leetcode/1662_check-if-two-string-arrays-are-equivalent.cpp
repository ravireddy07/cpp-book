// Problem Statement: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string a = "", b = "";
        for (auto i : word1)
            a += i;
        for (auto i : word2)
            b += i;
        return a == b;
    }
};

int main()
{
    Solution a;
    vector<string> in1 = {"ab",
                          "c"},
                   in2 = {"a",
                          "bc"};
    cout << a.arrayStringsAreEqual(in1, in2) << endl;
    return 0;
}
