// https://leetcode.com/problems/keyboard-row/

#include <iostream>
using namespace std;

class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";
        set<int> s;
        vector<string> ans;
        for (const auto word : words)
        {
            s.clear();
            for (const auto c : word)
            {
                char t = tolower(c);
                if (row1.find(t) != string::npos)
                    s.insert(1);
                else if (row2.find(t) != string::npos)
                    s.insert(2);
                else if (row3.find(t) != string::npos)
                    s.insert(3);
            }
            if (s.size() == 1)
                ans.push_back(word);
        }
        return ans;
    }
};

int main()
{
    Solution a;
    vector<string> input = {"Hello",
                            "Alaska",
                            "Dad",
                            "Peace"};
    vector<string> show = a.findWords(input);
    cout << "[";
    for (int i = 0; i < show.size(); i++)
    {
        if (i == show.size() - 1)
            cout << show[i];
        else
            cout << show[i] << ", ";
    }
    cout << "]";
    return 0;
}