// Problem Statement:  https://leetcode.com/problems/find-the-duplicate-number/

#include <bits/stdc++.h>
using namespace std;

// Solution #1
class Solution
{
public:
    int findDuplicate(vector<int> nums)
    {
        int slow = nums[0];
        int fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        fast = nums[0];

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }

    int findDuplicate(vector<int> nums)
    {
        int visited;
        for (int i = 0; i < nums.size(); i++)
        {
            visited = abs(nums[i]);
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
    cout << a.findDuplicate({1, 3, 4, 2, 2}) << "\n";
    return 0;
}
