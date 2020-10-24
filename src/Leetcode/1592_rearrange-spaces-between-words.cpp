// https://leetcode.com/problems/rearrange-spaces-between-words/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reorderSpaces(string text)
    {
        int spaces = 0;
        string word, s;
        vector<string> words;
        for (auto ch : text)
        {
            if (ch == ' ')
            {
                ++spaces;
                if (!word.empty())
                    words.push_back(word);
                word = "";
            }
            else
                word += ch;
        }
        if (!word.empty())
            words.push_back(word);
        if (words.size() == 1)
            return words.back() + string(spaces, ' ');
        int gap = spaces / (words.size() - 1), suff = spaces % (words.size() - 1);
        for (auto w : words)
            s += w + string(gap, ' ');
        return s.substr(0, s.size() - gap) + string(suff, ' ');
    }
};
/* 
// need to be tested

class Solution
{
public:
    string reorderSpaces(string text)
    {
        string word = "";
        string res = "";
        for (int i = 0; i < text.length(); i++)
        {
            if (text[i] != ' ')
                word += text[i];
            else
            {
                if (word != "")
                {
                    res += word + " ";
                }
                word = "";
            }
        }
        return res;
    }
}; */

int main()
{
    Solution a;
    cout << a.reorderSpaces("  this   is  a sentence ") << endl;
    return 0;
}