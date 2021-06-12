// Problem Statemnet: https://leetcode.com/problems/array-partition-i/

// Problem Discussion: https://leetcode.com/problems/array-partition-i/discuss/850851/C%2B%2B-Best-Solution-or-Explanation-with-another-Example

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int arrayPairSum(vector<int> nums)
    {
        sort(nums.begin(), nums.end());
        int sum = 0, count = 0;
        for (int i = nums.size() - 1; i >= 0; i -= 2)
            if (count != nums.size() / 2)
            {
                sum += min(nums[i], nums[i - 1]);
                count++;
            }
        return sum;
    }
};

// Optimized Solution
class Solution
{
public:
    int arrayPairSum(vector<int> nums)
    {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = nums.size() - 1; i >= 0; i -= 2)
            sum += nums[i - 1];
        return sum;
    }
};

int main()
{
    Solution a;
    cout << a.arrayPairSum({1, 4, 3, 2}) << "\n";
    return 0;
}
