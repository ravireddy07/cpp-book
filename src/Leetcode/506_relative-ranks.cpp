// Problem Statement: https://leetcode.com/problems/relative-ranks/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> nums)
    {
        vector<string> ans;
        map<string, int> mp;
        vector<int> num = nums;
        sort(nums.begin(), nums.end());
        int rank = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            mp[to_string(nums[i])] = rank;
            rank++;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            int r = nums.size() - mp[to_string(num[i])] + 1;
            if (r == 1)
                ans.push_back("Gold Medal");
            else if (r == 2)
                ans.push_back("Silver Medal");
            else if (r == 3)
                ans.push_back("Bronze Medal");
            else
                ans.push_back(to_string(r));
        }
        return ans;
    }
};

int main()
{
    Solution a;
    vector<string> show = a.findRelativeRanks({5, 4, 3, 2, 1});
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
