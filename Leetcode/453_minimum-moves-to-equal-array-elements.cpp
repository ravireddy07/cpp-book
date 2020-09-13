// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        int res = 0;
        int min = *min_element(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
            res += nums[i] - min;
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> input = {1, 2, 3};
    cout << a.minMoves(input) << endl;
    return 0;
}