// Problem Statement: https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#

// Solution: https://www.geeksforgeeks.org/minimize-the-maximum-difference-between-the-heights/

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int getMinDiff(vector<int> arr, int n, int k)
{
    if (n == 1)
        return 0;
    sort(arr.begin(), arr.end());

    int ans = arr[n - 1] - arr[0];

    int small = arr[0] + k;
    int big = arr[n - 1] - k;
    if (small > big)
        swap(small, big);

    for (int i = 1; i < n - 1; i++)
    {
        int subtract = arr[i] - k;
        int add = arr[i] + k;

        if (subtract >= small || add <= big)
            continue;

        if (big - subtract <= add - small)
            small = subtract;
        else
            big = add;
    }
    return min(ans, big - small);
}

int main()
{
    vector<int> arr = {2, 6, 3, 4, 7, 2, 10, 3, 2, 1};
    // {1, 10, 14, 14, 14, 15}, k=6
    // {1, 5, 15, 10}, k=3
    // {1 3 5 8}, k=2
    cout << getMinDiff(arr, arr.size(), 5);
    return 0;
}
