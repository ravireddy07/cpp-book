// https://leetcode.com/problems/contains-duplicate/

#include <iostream>
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
    cout << a.containsDuplicate(input) << endl;
    return 0;
}