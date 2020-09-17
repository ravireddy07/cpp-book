// https://leetcode.com/problems/valid-anagram/

#include <iostream>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int count[26] = {0};
        if (s.size() != t.size())
            return false;

        for (int i = 0; i < s.size(); ++i)
        {
            ++count[s[i] - 'a'];
            --count[t[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i)
        {
            if (count[i])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution a;
    cout << a.isAnagram("anagram", "nagaram") << endl;
    return 0;
}