// Problem Statement: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int> nums)
    {
        int len = nums.size();
        int minNum = INT_MAX;
        int maxNum = INT_MIN;
        int i = 0;
        while (i < len && (i + 1) < len && nums[i] <= nums[i + 1])
            i++;
        for (i = i; i < len; i++)
            minNum = min(minNum, nums[i]);

        int j = len - 1;
        while (j >= 0 && (j - 1) >= 0 && nums[j - 1] <= nums[j])
            j--;

        for (j = j; j >= 0; j--)
            maxNum = max(maxNum, nums[j]);

        int minpos = -1;
        for (i = 0; i < len; i++)
        {
            if (nums[i] > minNum)
            {
                minpos = i;
                break;
            }
        }

        int maxpos = -1;
        for (i = len - 1; i >= 0; i--)
        {
            if (nums[i] < maxNum)
            {
                maxpos = i;
                break;
            }
        }
        return (maxpos - minpos <= 0) ? 0 : maxpos - minpos + 1;
    }
};

int main()
{
    Solution a;
    cout << a.findUnsortedSubarray({2, 6, 4, 8, 10, 9, 15}) << "\n";
    return 0;
}
