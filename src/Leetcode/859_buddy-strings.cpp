// https://leetcode.com/problems/buddy-strings/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool buddyStrings(string A, string B)
    {
        char s = '0';
        if (A.size() != B.size() || A.size() <= 1 || B.size() <= 1)
            return 0;
        if (A == B && set<char>(A.begin(), A.end()).size() < A.size())
            return true;

        string a = "", b = "";
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] != B[i])
            {
                a += A[i];
                b += B[i];
            }
            else if (s == '0')
                s = A[i];
            else if (s != A[i])
                return 0;
        }
        swap(a[0], a[1]);
        if (a == b)
            return 1;
        return 0;
    }
};

int main()
{
    Solution a;
    cout << a.buddyStrings("abab", "abab") << endl;
    return 0;
}