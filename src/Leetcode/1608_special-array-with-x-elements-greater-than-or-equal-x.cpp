// Problem Statement: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int specialArray(vector<int> nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 1)
        {
            auto itr = lower_bound(nums.begin(), nums.end(), i + 1);
            int size = nums.size();
            int index = itr - nums.begin();
            if (size - index == i + 1)
                return i + 1;
        }
        return -1;
    }
};

int main()
{
    Solution a;
    cout << a.specialArray({0, 4, 3, 0, 4}) << "\n";
    return 0;
}
