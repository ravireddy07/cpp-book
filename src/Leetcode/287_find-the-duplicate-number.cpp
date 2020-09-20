// https://leetcode.com/problems/find-the-duplicate-number/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int visited;
        for (int i = 0; i < nums.size(); i++)
        {
            visited = ::abs(nums[i]);
            if (nums[visited] < 0)
                return visited;
            else
                nums[visited] = -nums[visited];
        }
        return -1;
    }
};

int main()
{
    Solution a;
    vector<int> input = {1, 1, 2};
    cout << a.findDuplicate(input) << endl;
    return 0;
}