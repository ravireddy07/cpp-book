// https://leetcode.com/problems/longest-continuous-increasing-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int res = 0, count = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
                count++;
            else
            {
                if (count > res)
                    res = count;
                count = 1;
            }
        }
        if (count > res)
            res = count;
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> input = {1, 3, 5, 4, 7};
    cout << a.findLengthOfLCIS(input) << endl;
    return 0;
}
