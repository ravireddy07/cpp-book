// Problem Statement: https://leetcode.com/problems/contains-duplicate/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        // return nums.size() > set<int>(nums.begin(), nums.end()).size();
        set s(nums.begin(), nums.end());
        if (s.size() == nums.size())
            return false;
        return true;
    }
};

int main()
{
    Solution a;
    vector<int> input = {1, 2, 3, 1};
    cout << a.containsDuplicate(input) << "\n";
    return 0;
}
