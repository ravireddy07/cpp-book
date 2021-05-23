// Problem Statement: https://leetcode.com/problems/maximum-product-subarray/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> nums)
    {
        int maxNum = nums[0], minNum = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int temp1 = maxNum, temp2 = minNum;
            maxNum = max(temp2 * nums[i], max(temp1 * nums[i], nums[i]));
            minNum = min(temp2 * nums[i], min(temp1 * nums[i], nums[i]));
            res = max(res, maxNum);
        }
        return res;
    }
};

int main()
{
    Solution a;
    cout << a.maxProduct({-3, -1, -1}) << "\n";
    return 0;
}
