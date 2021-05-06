// Problem Statement: https://leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> arr)
    {
        if (arr.size() == 0)
            return 0;
        int n = arr.size();
        int res = 0;
        int left[n];
        int right[n];
        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));
        left[0] = arr[0];
        left[n - 1] = arr[n - 1];
        right[0] = arr[0];
        right[n - 1] = arr[n - 1];
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] >= left[i - 1])
                left[i] = arr[i];
            else
                left[i] = left[i - 1];
        }
        for (int i = arr.size() - 2; i >= 0; i--)
        {
            if (arr[i] >= right[i + 1])
                right[i] = arr[i];
            else
                right[i] = right[i + 1];
        }
        for (int i = 0; i < n; i++)
        {
            res = res + (min(left[i], right[i]) - arr[i]);
        }
        return res;
    }
};

int main()
{
    Solution a;
    cout << a.trap({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}) << "\n";
    return 0;
}
