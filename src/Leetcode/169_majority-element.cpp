// Problem Statement: https://leetcode.com/problems/majority-element/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> nums)
    {
        if (nums.size() == 0)
            return -1;
        if (nums.size() == 1)
            return nums[0];
        int count = 1, limit = nums.size() / 2, res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
                count++;
            else
            {
                if (count > limit && res < count)
                    res = nums[i];
                count = 1;
            }
        }
        if (count > limit && count > res)
            res = nums[nums.size() - 1];
        return res;
    }
};

/*
// n/3 Times
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        if (nums.size() == 0)
            return {};
        if (nums.size() == 1)
            return nums;
        int count = 1, limit = nums.size() / 3;
        vector<int> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
                count++;
            else
            {
                if (count > limit)
                    res.push_back(nums[i]);
                count = 1;
            }
        }
        if (count > limit)
            res.push_back(nums[nums.size() - 1]);
        return res;
    }
};
*/

int main()
{
    Solution a;
    cout << a.majorityElement({2, 2, 1, 1, 2, 2}) << "\n";
    return 0;
}
