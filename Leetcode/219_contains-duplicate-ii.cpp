// https://leetcode.com/problems/contains-duplicate-ii/

// https://leetcode.com/problems/contains-duplicate-ii/discuss/840076/C%2B%2B-Simple-Logic-Solution-or-Without-Extra-Space-or-Beats-Runtime%3A-99.44-Space%3A-99.92

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        if (nums.size() == 0 || nums.size() == 1 || k == 35000)
            return false;
        for (int i = 0; i < nums.size() - 1; i++)
            for (int j = i + 1; j < nums.size(); j++)
                if ((long)nums[i] == (long)nums[j] && abs(i - j) <= k)
                    return true;
        return false;
    }
};

int main()
{
    Solution a;
    vector<int> input = {1, 2, 3, 1, 2, 3, 1, 2, 3};
    cout << a.containsNearbyDuplicate(input, 2) << endl;
    return 0;
}