// Problem Statement: https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> rowSum, vector<int> colSum)
    {
        int h = rowSum.size();
        int w = colSum.size();
        vector<vector<int>> res(h, vector<int>(w));

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (rowSum[i] > 0 || colSum[j])
                {
                    int d = min(rowSum[i], colSum[j]);
                    res[i][j] += d;
                    rowSum[i] -= d;
                    colSum[j] -= d;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> output = a.restoreMatrix({{3, 8}}, {{4, 7}});
    cout << "[";
    for (int i = 0; i < output.size(); i++)
    {
        cout << endl
             << " [";
        for (int j = 0; j < output[0].size(); j++)
        {
            if (j == output[0].size() - 1)
                cout << output[i][j];
            else
                cout << output[i][j] << ", ";
        }
        cout << "]";
    }
    cout << "\n"
         << "]";
    return 0;
}
