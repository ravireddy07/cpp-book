// Problem Statement: https://leetcode.com/problems/third-maximum-number/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                nums.erase(nums.begin() + i, nums.begin() + i + 1);
                i--;
            }
        }
        if (nums.size() < 3)
            return *max_element(nums.begin(), nums.end());
        return nums[nums.size() - 3];
    }
};

int main()
{
    Solution a;
    cout << a.thirdMax({3, 4, 2, 2, 2, 2, 3, 1}) << "\n";
    return 0;
}
