// Problem Statement: https://leetcode.com/problems/rotate-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> nums, int k)
    {
        k %= nums.size();
        reverse(nums.begin(), nums.end() - k);
        reverse(nums.begin() + 1 - k, nums.end());
        reverse(nums.begin(), nums.end());
    }

    void rotate(vector<int> nums, int k)
    {
        while (k--)
        {
            nums.insert(nums.begin(), nums.back());
            nums.pop_back();
        }
    }

    void rotate(vector<int> nums, int k)
    {
        int sz, n;
        sz = n = nums.size();
        k %= n;
        if (n < 2 || k < 1)
            return;
        for (int i = k; n > 0; ++i)
        {
            int j = i, prev = nums[(i - k) % k];
            while (n-- > 0)
            {
                std::swap(prev, nums[j]);
                j = (j + k) % sz;
                if (j == i)
                    break;
            }
        }
    }
};

int main()
{
    Solution a;
    vector<int> show = {1, 2, 3, 4, 5, 6, 7};
    a.rotate(show, 3);
    cout << "[";
    for (int i = 0; i < show.size(); i++)
    {
        if (i == show.size() - 1)
            cout << show[i];
        else
            cout << show[i] << ", ";
    }
    cout << "]";
    return 0;
}
