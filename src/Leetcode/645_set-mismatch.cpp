// https://leetcode.com/problems/set-mismatch/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
            while (nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != i + 1)
                return {nums[i], i + 1};
        return {};
    }
};

int main()
{
    Solution a;
    vector<int> input = {1, 2, 2, 4};
    vector<int> show = a.findErrorNums(input);
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