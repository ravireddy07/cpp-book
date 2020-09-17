// https://leetcode.com/problems/reshape-the-matrix/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        vector<vector<int>> v(r, vector<int>(c, 0));
        if (nums.size() == 0 || r * c != nums.size() * nums[0].size())
            return nums;
        int row = 0;
        int col = 0;
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < nums[0].size(); j++)
            {
                v[row][col] = nums[i][j];
                col++;
                if (col == c)
                {
                    row++;
                    col = 0;
                }
            }
        return v;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> input = {{1, 2}, {3, 4}};
    vector<vector<int>> show = a.distributeCandies(input, 1, 4);
    return 0;
}