// https://leetcode.com/problems/nim-game/

#include <iostream>
using namespace std;

class Solution
{
public:
    bool canWinNim(int n)
    {
        return n % 4 != 0;
    }
};

int main()
{
    Solution a;
    cout << a.canWinNim(4) << endl;
    return 0;
}