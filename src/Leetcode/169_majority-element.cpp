// https://leetcode.com/problems/majority-element/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int majorityElement(vector &nums)
    {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        if (len == 1)
            return nums[0];
        vector<int>::iterator it, it1;
        int f = 0, i, ans;
        for (i = 0; i < nums.size() && f != 1; i++)
        {
            it = lower_bound(nums.begin(), nums.end(), nums[i]);
            it1 = upper_bound(nums.begin(), nums.end(), nums[i]);
            cout << nums[i] << "   " << (it - nums.begin()) << "   " << (it1 - nums.begin()) << endl;
            if ((it1 - nums.begin()) - (it - nums.begin()) > len / 2)
                f = 1;
        }
        return nums[i];
    }
};

int main()
{
    Solution a;
    vector<int> input = {2, 2, 2, 1, 1, 1, 1, 2, 2};
    cout << a.majorityElement(input) << endl;
    return 0;
}