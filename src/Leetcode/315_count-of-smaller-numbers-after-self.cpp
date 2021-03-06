// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TLE
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            int count = 0;
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] > nums[j])
                    count++;
            res.push_back(count);
        }
        return res;
    }
    vector<int> countSmaller(vector<int> &nums)
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
    vector<int> in = {5, 2, 6, 1};
    vector<int> show = a.countSmaller(in);
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