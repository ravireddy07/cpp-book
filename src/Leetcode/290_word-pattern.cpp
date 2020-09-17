// https://leetcode.com/problems/word-pattern/

#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string str)
    {
        if (pattern.length() == 0 || str.length() == 0)
            return false;
        unordered_map<string, char> mp;
        set<char> st;
        int i = 0, cnt = 0;
        stringstream ss(str);
        string word = "";
        while (ss >> word)
        {
            if (mp.find(word) != mp.end())
            {
                if (mp[word] != pattern[i])
                    return false;
                i++;
            }
            else
            {
                if (st.find(pattern[i]) != st.end())
                    return false;
                else
                {
                    mp[word] = pattern[i];
                    st.insert(pattern[i]);
                    i++;
                }
            }
            cnt++;
        }
        if (cnt < pattern.length())
            return false;
        return true;
    }
};

int main()
{
    Solution a;
    cout << a.wordPattern("abba", "dog cat cat dog") << endl;
    return 0;
}
