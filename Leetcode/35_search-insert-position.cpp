// https://leetcode.com/problems/search-insert-position/

#include <iostream>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] == target)
                return i;
            else if (nums[i] < target)
                return i + 1;
        }
        return 0;
    }
};

int main()
{
    Solution a;
    vector<int> input = {1, 3, 5, 6};
    cout << a.searchInsert(input, 7) << endl;
    return 0;
}