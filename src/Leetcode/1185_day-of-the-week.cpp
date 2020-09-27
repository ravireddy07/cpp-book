// https://leetcode.com/problems/day-of-the-week/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution
{
public:
    string dayOfTheWeek(int day, int month, int year)
    {
        int days = 4;
        int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string dayName[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

        for (int i = 1971; i < year; i++)
        {
            if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0))
                days += 366;
            else
                days += 365;
        }
        for (int i = 1; i < month; i++)
        {
            if (i == 2 && ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))))
                days += 1;
            days += months[i];
        }
        days += day;
        return dayName[days % 7];
    }
};

int main()
{
    Solution a;
    cout << a.dayOfTheWeek(29, 2, 2016) << endl;
    return 0;
}
