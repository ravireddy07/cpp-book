//Problem Link:  https://leetcode.com/problems/single-number/

#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    int singleNumber(vector<int> &nums)
    {
        return std::accumulate(nums.begin(), nums.end(), 0, [](const int &a, const int &b) { return a ^ b; });
    }
    */
    int singleNumber(vector<int> &nums)
    {
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++)
            result ^= nums[i];
        return result;
    }
};

int main()
{
    Solution a;
    vector<int> input = {4, 1, 2, 1, 2};
    cout << a.singleNumber(input) << endl;
    return 0;
}
