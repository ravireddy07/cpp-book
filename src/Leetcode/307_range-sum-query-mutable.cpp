// Problem statement: https://leetcode.com/problems/range-sum-query-mutable/
// Problem Discussion: https://leetcode.com/problems/range-sum-query-mutable/discuss/843838/C%2B%2B-Simple-Brute-Force-Solution-or-93-Less-Space-or-Self-Explanatory

#include <bits/stdc++.h>
using namespace std;

// Runtime: 19% Space: 93%
class NumArray
{
public:
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

    void update(int i, int val)
    {
        ar[i] = val;
    }
};

int main()
{
    NumArray *obj = new NumArray({3, 0, 1, 4, 2});
    cout << obj->sumRange(2, 5) << "\n";
    obj->update(1, 2);
    cout << obj->sumRange(2, 5) << "\n";
    return 0;
}
