// https://leetcode.com/problems/subarray-product-less-than-k/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
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
    vector<int> in = {10, 5, 2, 6};
    cout << a.numSubarrayProductLessThanK(in, 100) << endl;
    return 0;
}