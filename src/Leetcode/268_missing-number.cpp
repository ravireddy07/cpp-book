// https://leetcode.com/problems/missing-number/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int sum_a;
        int n = nums.size();
        sum_a = n * (n + 1) / 2;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
            sum += nums[i];
        return sum_a - sum;
    }
};

int main()
{
    Solution a;
    vector<int> input = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << a.missingNumber(input) << endl;
    return 0;
}