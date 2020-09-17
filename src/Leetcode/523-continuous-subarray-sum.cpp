// https://leetcode.com/problems/continuous-subarray-sum/

#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Solution()
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        k = abs(k);
        int n = nums.size();
        if (!k)
        {
            for (int i = 0; i < n; ++i)
            {
                if (nums[i] == 0)
                    if (i < n - 1 && nums[i + 1] == 0)
                        return 1;
            }
            return 0;
        }
        long long pre = 0;
        unordered_map<long long, long long> m;
        m[0] = -1;
        for (int i = 0; i < n; ++i)
        {
            nums[i] = (nums[i] + k) % k;
            pre += nums[i];
            pre = (pre + k) % k;
            if (m.find(pre) == m.end())
                m[pre] = i;
            else if (m[pre] + 1 < i)
                return 1;
        }
        return 0;
    }
};

int main()
{
    vector<int> input = {23, 2, 4, 6, 7};
    Solution a;
    cout << a.checkSubarraySum(input, 6) << endl;
    return 0;
}