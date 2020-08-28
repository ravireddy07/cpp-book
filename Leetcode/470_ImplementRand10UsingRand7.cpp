// https://leetcode.com/problems/implement-rand10-using-rand7/

class Solution
{
public:
    int rand10()
    {
        int random = 0;
        for (int i = 0; i < 7; i++)
            random += rand7();
        return random % 10 + 1;
    }
};