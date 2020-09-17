// https://leetcode.com/problems/image-overlap/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int CountShifting(vector<vector<int>> &A, vector<vector<int>> &res, int left, int right)
    {
        int x = 0;
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < A[0].size(); j++)
                x += A[i][j] * res[i + right][j + left];
        return x;
    }

    int largestOverlap(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        int n = A.size(), result = 0;
        vector<vector<int>> res(3 * n - 2, vector<int>(3 * n - 2, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                res[i + n - 1][j + n - 1] = B[i][j];
        for (int left = 0; left < 2 * n - 1; left++)
            for (int right = 0; right < 2 * n - 1; right++)
                result = max(result, CountShifting(A, res, left, right));
        return result;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> input1 = {{1, 1, 0}, {0, 1, 0}, {0, 1, 0}};
    vector<vector<int>> input2 = {{0, 0, 0}, {0, 1, 1}, {0, 0, 1}};
    cout << a.largestOverlap(input1, input2) << endl;
    return 0;
}