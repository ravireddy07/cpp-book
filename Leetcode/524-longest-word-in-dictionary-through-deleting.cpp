// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/

#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool comp(string a, string b)
{
    if (a.size() == b.size())
        return a < b;
    return a.size() > b.size();
}

class Solution
{
public:
    int LCS(string a, string b)
    {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size())
        {
            if (a[i] == b[j])
                j++;
            i++;
        }
        return (j == b.size());
    }
    string findLongestWord(string s, vector<string> &d)
    {
        //sort(d.begin(),d.end(), comp);
        string ret = "";
        for (auto word : d)
        {
            if (LCS(s, word))
            {
                if (ret == "")
                    ret = word;
                else
                {
                    if (comp(word, ret))
                        ret = word;
                }
            }
        }
        return ret;
    }
};

int main()
{
    vector<string> input = {"ale", "apple", "monkey", "plea"};
    Solution a;
    cout << a.findLongestWord("abpcplea", input) << endl;
    return 0;
}