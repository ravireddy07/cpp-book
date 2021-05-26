// Problem Statement: https://leetcode.com/problems/product-of-array-except-self/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> nums)
    {
        int N = nums.size();
        vector<int> res(N);
        res[0] = 1;

        int i = 1;
        for (; i < N; ++i)
            res[i] = res[i - 1] * nums[i - 1];

        int right = 1;
        i = N - 1;
        for (; i >= 0; --i)
        {
            res[i] = res[i] * right;
            right = right * nums[i];
        }
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> show = a.productExceptSelf({1, 2, 3, 4});
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
