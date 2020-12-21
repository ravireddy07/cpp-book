// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> nums)
    {
        if (nums.size() < 2)
            return nums.size();
        int size = nums.size();
        for (int i = 0; i < size; ++i)
        {
            int k = 0;
            for (int j = i + 1; j < size; ++j)
                if (nums[i] == nums[j])
                    ++k;
            if (k > 0)
                nums.erase(nums.begin() + i, nums.begin() + i + k);
            size -= k;
        }
        return nums.size();
    }
};

int main()
{
    Solution a;
    cout << a.removeDuplicates({1, 1, 2}) << endl;
    return 0;
}
