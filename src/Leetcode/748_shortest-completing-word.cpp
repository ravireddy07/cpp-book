// Problem Statement: https://leetcode.com/problems/shortest-completing-word/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string shortestCompletingWord(string licensePlate, vector<string> words)
    {
        int mp[26] = {0};
        int index = -1;

        for (auto c : licensePlate)
            if (isalpha(c))
                ++mp[tolower(c) - 'a'];

        for (int item = 0; item < words.size(); ++item)
        {
            int tmap[26] = {0};
            for (auto c : words[item])
                ++tmap[c - 'a'];
            int i;
            for (i = 0; i < 26; ++i)
            {
                if (!mp[i])
                    continue;
                if (mp[i] > tmap[i])
                    break;
            }

            if (i == 26)
                index = index > -1 ? words[index].size() <= words[item].size() ? index : item : item;
        }
        return index > -1 ? words[index] : "";
    }
};

int main()
{
    Solution a;
    cout << a.shortestCompletingWord("1s3 PSt", {"step", "steps", "stripe", "stepple"}) << "\n";
    return 0;
}
