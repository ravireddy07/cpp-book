// Problem Statement: https://leetcode.com/problems/verifying-an-alien-dictionary/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAlienSorted(vector<string> words, string order)
    {
        for (int i = 0; i < words.size() - 1; i++)
        {
            const auto &word1 = words[i];
            const auto &word2 = words[i + 1];

            int i1 = 0, i2 = 0;
            while (word1[i1] == word2[i2])
                i1++, i2++;

            i1 = order.find(word1[i1]);
            i2 = order.find(word2[i2]);
            if (i1 > i2)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution a;
    cout << a.isAlienSorted({"hello", "leetcode"}, "hlabcdefgijkmnopqrstuvwxyz") << "\n";
    return 0;
}
