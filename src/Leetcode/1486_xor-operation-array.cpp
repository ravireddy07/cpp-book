// https://leetcode.com/problems/xor-operation-in-an-array/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int xorOperation(int n, int start)
    {
        int res = start, temp = 2;
        for (int i = 1; i < n; i++)
        {
            res ^= (start + temp);
            temp += 2;
        }
        return res;
    }
};

int main()
{
    Solution a;
    cout << a.xorOperation(5, 0) << endl;
    return 0;
}