// Problem Statement: https://leetcode.com/problems/lucky-numbers-in-a-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> matrix)
    {
        vector<int> vRet;
        int j;
        for (int i = 0; i < matrix.size(); ++i)
        {
            int min_pos = min_element(matrix[i].begin(), matrix[i].end()) - matrix[i].begin();
            for (j = 0; j < matrix.size(); ++j)
            {
                if (matrix[i][min_pos] < matrix[j][min_pos])
                    break;
            }
            if (j == matrix.size())
                vRet.push_back(matrix[i][min_pos]);
        }
        return vRet;
    }
};

int main()
{
    Solution a;
    cout << a.luckyNumbers({{3, 7, 8}, {9, 11, 13}, {15, 16, 17}}) << "\n";
    return 0;
}
