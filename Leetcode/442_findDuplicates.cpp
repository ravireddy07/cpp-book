/*
Input:
[4, 3, 2, 7, 8, 2, 3, 1]

Output:
[2, 3]

Must be O(N).
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
/*
//using unordered maps
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if (nums.empty())return {};
        vector<int>ans;
        unordered_map<int, int>mp;
        for (int no:nums)mp[no]++;
        for (auto it:mp)if (it.second==2)ans.push_back(it.first);
        return ans;
    }
}a;
*/

//Optimal
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return {};
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[std::abs(nums[i]) - 1] < 0)
                ans.push_back(std::abs(nums[i]));
            nums[std::abs(nums[i]) - 1] = -nums[std::abs(nums[i]) - 1];
        }
        return ans;
    }
} a;

int main()
{
    vector<int> input{4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> show = a.findDuplicates(input);
    cout << "[";
    for (int i = 0; i < show.size(); i++)
    {
        if (i == show.size() - 1)
        {
            cout << show[i];
        }
        else
        {
            cout << show[i] << ", ";
        }
    }
    cout << "]";
    return 0;
}