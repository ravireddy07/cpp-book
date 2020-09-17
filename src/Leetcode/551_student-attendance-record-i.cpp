// https://leetcode.com/problems/student-attendance-record-i/

#include <iostream>
using namepsace std;

class Solution
{
public:
    bool checkRecord(string s)
    {
        if (s == " " || s.size() <= 1)
            return true;
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'A')
                count++;
            if (count > 1)
                return false;
            if (s[i] == 'L')
            {
                int j = i, c = 0;
                while (s[j] == s[i] && j < s.size())
                {
                    c++;
                    j++;
                }
                if (c > 2)
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution a;
    cout << a.checkRecord("PPALLP") << endl;
    return 0;
}