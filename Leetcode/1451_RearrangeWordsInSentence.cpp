// https://leetcode.com/problems/rearrange-words-in-a-sentence/

#include <iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution
{
public:
    string arrangeWords(string text)
    {
        text[0] = tolower(text[0]);
        stringstream ss(text);
        string word;
        map<int, string> res;

        while (ss >> word)
            res[word.size()] += word + " ";

        string ans;

        for (auto id = res.begin(); id != res.end(); id++)
            ans += id->second;

        ans.pop_back();
        ans[0] = toupper(ans[0]);

        return ans;
    }
};
/*
vector<string> split(string s)
{
    string word = "";
    vector<string> res;
    for (auto c : s)
    {
        if (c == ' ')
        {
            res.push_back(word);
            word = "";
        }
        else
        {
            word += c;
        }
    }
    res.push_back(word);
    return res;
}*/

int main()
{
    Solution a;
    cout << a.arrangeWords("Leetcode is cool") << endl;
    return 0;
}