// https://leetcode.com/problems/base-7/

#include <iostream>
using namespace std;

class Solution
{
public:
    string convertToBase7(int num)
    {
        string res;
        int negative = num < 0;
        num = abs(num);
        while (num)
        {
            res += (char)(num % 7 + '0');
            num /= 7;
        }
        if (negative)
            res.push_back('-');
        reverse(res.begin(), res.end());
        return (res.empty() ? "0" : res);
    }
};

int main()
{
    Solution a;
    cout << a.convertToBase7(100) << endl;
    return 0;
}