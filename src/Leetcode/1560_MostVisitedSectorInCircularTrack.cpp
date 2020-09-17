// https://leetcode.com/problems/most-visited-sector-in-a-circular-track/

#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> mostVisited(int n, vector<int> &A)
    {
        vector<int> res;
        for (int i = A[0]; i <= A[A.size() - 1]; ++i)
            res.push_back(i);
        if (res.size() > 0)
            return res;
        for (int i = 1; i <= A[A.size() - 1]; ++i)
            res.push_back(i);
        for (int i = A[0]; i <= n; ++i)
            res.push_back(i);
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> input = [ 1, 3, 1, 2 ];
    int N = 2;
    vector<int> show = a.mostVisited(N, input);

    cout << "[";
    for (int i = 0; i < show.size(); i++)
    {
        if (i == show.size() - 1)
        {
            cout << show[i];
        }
        else
        {
            cout << show[i] << ", ";
        }
    }
    cout << "]";
    return 0;
}