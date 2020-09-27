// https://leetcode.com/problems/day-of-the-year/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int dayOfYear(string date)
    {
        int res = 0;
        int day = stoi(date.substr(8, 2));
        int month = stoi(date.substr(5, 2));
        int year = stoi(date.substr(0, 4));
        int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = 1; i < month; i++)
        {
            if (i == 2 && ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))))
                res += 1;
            res += months[i];
        }
        res += day;
        return res;
    }
};

int main()
{
    Solution a;
    cout << a.dayOfYear("2003-03-01") << endl;
    return 0;
}
