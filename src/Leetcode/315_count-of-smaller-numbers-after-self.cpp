// Problem Statement: https://leetcode.com/problems/count-of-smaller-numbers-after-self/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countSmaller(vector<int> nums)
    {
        if (nums.empty())
            return {};
        vector<int> temp;
        vector<int> counts(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            auto end = lower_bound(temp.begin(), temp.end(), nums[i]);
            counts[i] = end - temp.begin();
            temp.insert(end, nums[i]);
        }
        return counts;
    }
};

int main()
{
    Solution a;
    vector<int> show = a.countSmaller({5, 2, 6, 1});
    cout << "[";
    for (int i = 0; i < show.size(); i++)
    {
        if (i == show.size() - 1)
            cout << show[i];
        else
            cout << show[i] << ", ";
    }
    cout << "]" << endl;
    return 0;
}
