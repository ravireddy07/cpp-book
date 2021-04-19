// Problem Statement: Problem Link:  https://leetcode.com/problems/happy-number/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        vector<int> digits;
        while (n != 1)
        {
            int k = n;
            int sum = 0;
            while (k)
            {
                sum += pow((k % 10), 2);
                k /= 10;
            }
            if (find(begin(digits), end(digits), sum) != digits.end())
                return 0;
            digits.push_back(sum);
            n = k = sum;
        }
        return 1;
    }
};

int main()
{
    Solution a;
    cout << a.isHappy(2) << "\n";
    return 0;
}
