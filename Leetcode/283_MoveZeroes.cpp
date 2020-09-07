//Problem Link:  https://leetcode.com/problems/move-zeroes/

#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i])
                swap(nums[i], nums[j++]);
        }
        /*
        cout << "[";
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == nums.size() - 1)
            {
                cout << nums[i];
            }
            else
            {
                cout << nums[i] << ", ";
            }
        }
        cout << "]";
        */
    }
};

int main()
{
    Solution a;
    vector<int> input = {0, 1, 0, 3, 12};
    cout << a.moveZeroes(input) << endl;
    return 0;
}
