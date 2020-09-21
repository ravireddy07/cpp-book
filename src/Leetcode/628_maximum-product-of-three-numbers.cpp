// https://leetcode.com/problems/maximum-product-of-three-numbers/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return (max(nums[0] * nums[1] * nums[nums.size() - 1], nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3]));
    }
};

int main()
{
    Solution a;
    vector<int> input = {1, -4, -3, -1, -2, 60};
    cout << a.maximumProduct(input) << endl;
    return 0;
}