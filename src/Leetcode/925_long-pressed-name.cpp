// https://leetcode.com/problems/long-pressed-name/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        if (name[0] != typed[0])
            return 0;
        bool res = 0;
        int k = 0, count = 0; // count is track no. of char found
        // k is used to traverse typed char's
        char prev = 'a'; // next element either should be prev char or required char,
                         // if we found any other char, then return false
        for (int i = 0; i < name.length(); i++)
        {
            while (k < typed.length())
            {
                if (name[i] == typed[k])
                {
                    res = 1;
                    prev = typed[k];
                    k++;
                    count++;
                    break;
                }
                else if (prev != typed[k])
                    return 0;
                k++;
            }
        }

        if (count != name.length()) // this is to check wheither we found all char in name or not
            res = 0;

        if (k != typed.length()) // this is to check wheither typed has any other char after we found all name char
        {
            while (k < typed.length())
            {
                if (name[name.length() - 1] != typed[k])
                    return 0;
                k++;
            }
            res = 1; // this is for last char of name is repeating in typed
        }
        /* Example Test case:
               "alex"
               "alexxe"
        */
        return res;
    }
};

int main()
{
    Solution a;
    cout << a.isLongPressedName("pyplrz", "ppyypllr") << endl;
    return 0;
}