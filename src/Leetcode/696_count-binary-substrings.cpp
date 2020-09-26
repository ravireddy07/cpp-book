// https://leetcode.com/problems/count-binary-substrings/

#include <iostream>
using namespace std;

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int count = 0, i = 0;
        while (i < s.size())
        {
            int ones = 0, zeroes = 0;
            if (s[i] == '1')
            {
                while (s[i] == '1' && i < s.size())
                {
                    ones++;
                    i++;
                }
                int j = i;
                while (s[j] == '0' && j < s.size())
                {
                    zeroes++;
                    j++;
                }
            }
            else
            {
                while (s[i] == '0' && i < s.size())
                {
                    zeroes++;
                    i++;
                }
                int j = i;
                while (s[j] == '1' && j < s.size())
                {
                    ones++;
                    j++;
                }
            }
            count += min(ones, zeroes);
        }
        return count;
    }
};

int main()
{
    Solution a;
    cout << a.countBinarySubstrings("10101") << endl;
    return 0;
}