// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

#include <iostream>
using namespace std;

class Solution
{
public:
    int countOdds(int low, int high)
    {
        int count = 0;
        for (int i = low; i <= high; i++)
            if (i % 2 != 0)
                count++;
        return count;
        //return (high + 1) / 2 - low / 2;
    }
};

int main()
{
    Solution a;
    cout << a.countOdds(3, 7) << endl;
    return 0;
}