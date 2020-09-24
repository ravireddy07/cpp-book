// https://leetcode.com/problems/running-sum-of-1d-array/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> res;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            res.push_back(sum);
        }
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> input = {1, 2, 3, 4};
    vector<int> show = a.runningSum(input);
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