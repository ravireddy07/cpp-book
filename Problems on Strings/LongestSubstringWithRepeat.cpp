#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() == 0)
            return 0;
        unordered_map<char, int> mp;
        int maxs = 1;
        int prev = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (mp.find(s[i]) != mp.end() && mp[s[i]] >= prev)
            {
                prev = mp[s[i]] + 1;
                mp[s[i]] = i;
            }
            maxs = max(maxs, i - prev + 1);
            mp[s[i]] = i;
        }
        return maxs;
    }
};

int main()
{
    Solution a;
    int result = a.lengthOfLongestSubstring("abcabcbb");
    cout << result << endl;
    return 0;
}
