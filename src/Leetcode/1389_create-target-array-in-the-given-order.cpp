// https://leetcode.com/problems/create-target-array-in-the-given-order/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
            auto iter = res.insert(res.begin() + index[i], nums.begin() + i, nums.begin() + i + 1);
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> input1 = {0, 1, 2, 3, 4}, input2 = {0, 1, 2, 2, 1};
    vector<int> show = a.createTargetArray(input1, input2);
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