// https://leetcode.com/problems/robot-bounded-in-circle/

#include <iostream>
using namepsace std;

class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        int x = 0, y = 0, dir = 1;
        // dir=1 -> North
        // dir=2 -> West
        // dir=3 -> South
        // dir=4 -> East
        //x,y -> current Position
        for (char i : instructions)
        {
            if (i == 'G')
            {
                if (dir == 1)
                    y += 1;
                if (dir == 2)
                    x -= 1;
                if (dir == 3)
                    y -= 1;
                if (dir == 4)
                    x += 1;
            }

            if (i == 'R')
            {
                if (dir == 4)
                    dir = 1;
                else
                    dir += 1;
            }

            if (i == 'L')
            {
                if (dir == 1)
                    dir = 4;
                else
                    dir -= 1;
            }
        }
        return ((x == 0 && y == 0) || (dir != 1));
    }
};

int main()
{
    Solution a;
    cout << a.isRobotBounded("GGLLGG") << endl;
    return 0;
}