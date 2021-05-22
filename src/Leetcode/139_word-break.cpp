// Problem Statement: https://leetcode.com/problems/word-break/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> wordDict)
    {
        if (wordDict.size() == 0)
            return false;

        set<string> dict;
        for (auto i : wordDict)
            dict.insert(i);

        int longestWord = 0;
        for (string word : dict)
            longestWord = max(longestWord, (int)word.size());

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = i - 1; j >= max(i - longestWord, 0); j--)
            {
                if (dp[j])
                {
                    string word = s.substr(j, i - j);
                    if (dict.find(word) != dict.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};

int main()
{
    Solution a;
    cout << a.wordBreak("applepenapple", {"apple", "lepp"}) <<"\n";
    return 0;
}