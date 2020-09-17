// https://leetcode.com/problems/reverse-words-in-a-string-iii/

#include <iostream>
#include <vector>
using namepsace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int i = 0, j, len = s.size();
        if (len < 2)
            return s;
        while (i < len)
        {
            j = i + 1;
            while (s[j] != ' ' && j < len)
                j++;
            reverse(begin(s) + i, begin(s) + j);
            i = j + 1;
        }
        return s;
    }
};

int main()
{
    Solution a;
    cout << a.reverseWords("s'teL ekat edoCteeL tsetnoc") << endl;
    return 0;
}