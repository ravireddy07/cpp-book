// Problem Statement:  https://leetcode.com/problems/ways-to-make-a-fair-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int waysToMakeFair(vector<int> nums)
    {
        int odd_sum, even_sum, skip;
        bool shift = 1; // when any index is removed/skiped, value's indexes will also change,
                        // that's why we use a shift to switch to odd-even an even-odd
        int res = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            skip = i;
            odd_sum = 0;
            even_sum = 0;
            for (int j = 0; j < nums.size(); ++j)
            {
                if (shift && skip != j)
                {
                    shift = shift ? 0 : 1;
                    odd_sum += nums[j];
                }
                else if (!shift && skip != j)
                {
                    shift = shift ? 0 : 1;
                    even_sum += nums[j];
                }
            }
            if (odd_sum == even_sum)
                res++;
        }
        return res;
    }
};

int main()
{
    Solution a;
    cout << a.waysToMakeFair({1, 1, 1}) << "\n";
    return 0;
}
