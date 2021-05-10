// Problem Statement:  https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> heights)
    {
        int n = heights.size();
        vector<int> rightSmallest(n, n), leftSmallest(n, -1), stk;
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() and heights[i] < heights[stk.back()])
                rightSmallest[stk.back()] = i, stk.pop_back();
            stk.push_back(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!stk.empty() and heights[i] < heights[stk.back()])
                leftSmallest[stk.back()] = i, stk.pop_back();
            stk.push_back(i);
        }
        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            int height = heights[i];
            int width = rightSmallest[i] - leftSmallest[i] - 1;
            int curArea = height * width;
            maxArea = max(maxArea, curArea);
        }
        return maxArea;
    }
};

int main()
{
    Solution a;
    cout << a.largestRectangleArea({2, 1, 5, 6, 2, 3}) << "\n";
    return 0;
}
