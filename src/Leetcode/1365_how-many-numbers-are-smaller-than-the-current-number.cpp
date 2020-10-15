// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < nums.size(); j++)
                if (i != j && nums[i] > nums[j])
                    count++;
            res.push_back(count);
        }
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> in = {8, 1, 2, 2, 3};
    vector<int> show = a.smallerNumbersThanCurrent(in);
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