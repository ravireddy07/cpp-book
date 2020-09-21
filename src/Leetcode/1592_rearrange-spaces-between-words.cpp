// https://leetcode.com/problems/rearrange-spaces-between-words/

#include <iostream>
#include <vector>
#include <algorithm>
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

int main()
{
    Solution a;
    cout << a.reorderSpaces("  this   is  a sentence ") << endl;
    return 0;
}