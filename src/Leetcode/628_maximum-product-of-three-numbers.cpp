// Problem Statement: https://leetcode.com/problems/maximum-product-of-three-numbers/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int> nums)
    {
        sort(nums.begin(), nums.end());
        return (max(nums[0] * nums[1] * nums[nums.size() - 1], nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3]));
    }
};

int main()
{
    Solution a;
    cout << a.maximumProduct({1, -4, -3, -1, -2, 60}) << "\n";
    return 0;
}
