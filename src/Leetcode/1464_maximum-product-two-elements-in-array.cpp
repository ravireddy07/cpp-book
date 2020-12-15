// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (((nums[i] - 1) * (nums[j] - 1)) > res)
                {
                    res = ((nums[i] - 1) * (nums[j] - 1));
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> input = {1, 5, 4, 5};
    cout << a.maxProduct(input) << endl;
    return 0;
}