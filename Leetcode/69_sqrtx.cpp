// https://leetcode.com/problems/sqrtx/

#include <iostream>
using namespace std;

class Solution
{
public:
    int sqrtx(int x)
    {
        return sqrt(x);
    }
};

int main()
{
    Solution a;
    cout << a.sqrtx(3) << endl;
    return 0;
}