// Problem Statement: https://leetcode.com/problems/longest-palindrome/

#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(string s)
{
    vector<int> v(255, 0);
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        v[s[i] - 'A']++;
        if (v[s[i] - 'A'] % 2 == 0)
            ans += 2;
    }
    return s.size() > ans ? ans + 1 : ans;
}

int main()
{
    cout << longestPalindrome("abccccdd") << "\n"; // Result: 7 (dccaccd)
    return 0;
}
