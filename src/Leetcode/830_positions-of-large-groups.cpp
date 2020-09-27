// https://leetcode.com/problems/positions-of-large-groups/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string s)
    {
        vector<vector<int>> res;
        int count = 1, len = s.length();
        for (int i = 1; i < len; i++)
        {
            if (s[i] == s[i - 1])
                count += 1;
            else
            {
                if (count >= 3)
                    res.push_back({i - count, i - 1});
                count = 1;
            }
        }
        if (count >= 3)
            res.push_back({len - count, len - 1});
        return res;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> show = a.largeGroupPositions("aaa");
    return 0;
}
