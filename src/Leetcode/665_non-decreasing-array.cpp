// https://leetcode.com/problems/non-decreasing-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int cnt = 1, n = nums.size();
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] < nums[i - 1])
            {
                if (cnt == 0)
                    return false;
                if (i == 1 || nums[i] >= nums[i - 2])
                    nums[i - 1] = nums[i];
                else
                    nums[i] = nums[i - 1];
                --cnt;
            }
        }
        return true;
    }
};

/*
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        int max = nums[0];
        
        if (nums.size() <= 2)
            return true;
        
        for (int i = 1; i < nums.size(); i++)
        {
            if ( nums[i] < nums[i-1] )
            {
                if (i+1 < nums.size() && nums[i-1] < nums[i+1])
                {
                    nums[i] = nums[i-1];
                    break;
                }
                if (i+1 < nums.size() && nums[i-1] > nums[i+1])
                {
                    nums[i-1] = nums[i];
                    break;
                } 
                nums[i] = nums[i-1];
                break;
            }
        }
        
        for (int i = 1; i < nums.size(); i++)
        {
            if ( nums[i] < nums[i-1] )
                return false;
        }
        return true;
    }
};
*/
int main()
{
    Solution a;
    vector<int> input = {4, 2, 3};
    cout << a.checkPossibility(input) << endl;
    return 0;
}
