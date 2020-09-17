// https://leetcode.com/problems/consecutive-characters/

#include <iostream>
using namespace std;

class Solution
{
public:
    int maxPower(string s)
    {
        int res = 0, temp = 1;
        for (int i = 1; i < s.length(); ++i)
        {
            if (s[i] == s[i - 1])
                temp += 1;
            else
            {
                if (temp > res)
                    res = temp;
                temp = 1;
            }
        }
        if (temp > res)
            res = temp;
        return res;
    }
};

int main()
{
    Solution a;
    cout << a.maxPower("leetcode") << endl;
    return 0;
}