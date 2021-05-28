// Problem Statement: https://leetcode.com/problems/range-sum-query-immutable/

#include <bits/stdc++.h>
using namespace std;

vector<int> sumIndices(100000);
class NumArray
{
public:
    NumArray(vector<int> nums)
    {
        if (nums.size() == 0)
            return;
        sumIndices[0] = nums[0];
        for (int f = 1; f < nums.size(); ++f)
            sumIndices[f] = nums[f] + sumIndices[f - 1];
    }

    int sumRange(int i, int j)
    {
        if (i == 0)
            return sumIndices[j];
        else
            return sumIndices[j] - sumIndices[i - 1];
    }
    /***** Below another solution *****/
    vector<int> ar;
    NumArray(vector<int> nums)
    {
        if (nums.size() == 0)
            return;
        ar = nums;
    }

    int sumRange(int i, int j)
    {
        int sum = 0;
        for (int f = i; f <= j; ++f)
            sum += ar[f];
        return sum;
    }
};

int main()
{
    NumArray *obj = new NumArray({3, 0, 1, 4, 2});
    cout << obj->sumRange(2, 5) << "\n";
    return 0;
}
