// Problem Statement: https://leetcode.com/problems/longest-harmonious-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLHS(vector<int> nums)
    {
        unordered_map<int, int> um;
        for (int &x : nums)
            um[x]++;
        int ans = 0;
        for (auto itr = um.begin(); itr != um.end(); itr++)
        {
            int x = itr->first;
            if (um.count(x + 1))
            {
                int count = itr->second + um[x + 1];
                ans = max(ans, count);
            }
        }
        return ans;
    }

    // Brute Force
    int findLHS(vector<int> nums)
    {
        sort(nums.begin(), nums.end());

        vector<int> cnt;
        int res = 0, cntr = 1;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])
            {
                cntr++;
            }
            else
            {
                cnt.push_back(cntr);
                cntr = 1;
            }
        }
        cnt.push_back(cntr);

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])
            {
                nums.erase(nums.begin() + i);
                i--;
            }
        }

        for (int i = 1; i < nums.size(); i++)
            if ((abs(nums[i] - nums[i - 1]) == 0 or abs(nums[i] - nums[i - 1]) == 1) and (cnt[i] + cnt[i - 1] > res))
                res = cnt[i] + cnt[i - 1];

        return res;
    }
};

int main()
{
    Solution a;
    cout << a.findLHS({1, 3, 2, 2, 5, 2, 3, 7}) << "\n";
    return 0;
}
