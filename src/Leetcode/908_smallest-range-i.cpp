// https://leetcode.com/problems/smallest-range-i/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int smallestRangeI(vector<int> &A, int K)
    {
        int minV = A[0];
        int maxV = A[0];
        for (int &i : A)
        {
            minV = min(minV, i);
            maxV = max(maxV, i);
        }
        if (maxV - minV > 2 * K)
            return maxV - minV - 2 * K;
        return 0;
    }
};

int main()
{
    Solution a;
    vector<int> input = {0, 10};
    cout << a.smallestRangeI(input, 0) << endl;
    return 0;
}