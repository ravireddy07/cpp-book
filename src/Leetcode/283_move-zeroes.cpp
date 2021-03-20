//Problem Link:  https://leetcode.com/problems/move-zeroes/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i])
                swap(nums[i], nums[j++]);
    }
};

int main()
{
    Solution a;
    vector<int> input = {0, 1, 0, 3, 12};
    cout << a.moveZeroes(input) << "\n";
    return 0;
}
