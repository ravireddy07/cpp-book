// https://leetcode.com/problems/rectangle-overlap/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {
        return !(rec1[2] <= rec2[0] || // left
                 rec1[3] <= rec2[1] || // bottom
                 rec1[0] >= rec2[2] || // right
                 rec1[1] >= rec2[3]);
    }
};
int main()
{
    Solution a;
    vector<int> input1 = {0, 0, 2, 2}, input2 = {1, 1, 3, 3};
    cout << a.isRectangleOverlap(input1, input2) << endl;
    return 0;
}