// Problem Statement: https://leetcode.com/problems/subarray-product-less-than-k/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> nums, int k)
    {
        if (k == 0)
            return 0;
        int start = 0;
        int end = 0;
        int p = 1;
        int count = 0;

        while (end < nums.size())
        {
            p *= nums[end];
            while (start < nums.size() and p >= k)
            {
                p = p / nums[start];
                start++;
            }
            if (p < k)
                count += end - start + 1;
            end++;
        }
        return count;
    }
};

int main()
{
    Solution a;
    cout << a.numSubarrayProductLessThanK({10, 5, 2, 6}, 100) << "\n";
    return 0;
}
