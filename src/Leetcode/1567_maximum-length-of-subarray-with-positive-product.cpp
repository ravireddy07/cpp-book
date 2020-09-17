// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solve(vector<int> v)
    {
        int n = v.size();
        if (n == 0)
            return 0;
        int f = -1, s, c = 0;
        for (int i = 0; i < n; i++)
            if (v[i] < 0)
            {
                c++;
                if (f == -1)
                    f = i;
                s = i;
            }
        if (c % 2 == 0)
            return n;
        return max(n - f - 1, s);
    }
    int getMaxLen(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> v;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                ans = max(ans, solve(v));
                v.clear();
                continue;
            }
            else
                v.push_back(nums[i]);
        }
        ans = max(ans, solve(v));
        return ans;
    }
};

int main()
{
    Solution a;
    vector<int> input = {-3, -1, -1};
    cout << a.getMaxLen(input) << endl;
    return 0;
}