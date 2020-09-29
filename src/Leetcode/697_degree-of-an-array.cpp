// https://leetcode.com/problems/degree-of-an-array/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        unordered_map<int, int> count, first;
        int res = 0, degree = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (first.count(nums[i]) == 0)
                first[nums[i]] = i;
            if (++count[nums[i]] > degree)
            {
                degree = count[nums[i]];
                res = i - first[nums[i]] + 1;
            }
            else if (count[nums[i]] == degree)
                res = min(res, i - first[nums[i]] + 1);
        }
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> in = {1};
    cout << a.findShortestSubArray(in) << endl;
    return 0;
}