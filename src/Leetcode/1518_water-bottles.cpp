// Problem Statement: https://leetcode.com/problems/water-bottles/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int sum = numBottles;
        while (numBottles >= numExchange)
        {
            sum += numBottles / numExchange;
            numBottles = numBottles % numExchange + numBottles / numExchange;
            cout << numBottles % numExchange << "\n";
        }
        return sum;
    }
};

int main()
{
    Solution a;
    cout << a.numWaterBottles(15, 4) << "\n";
    return 0;
}
