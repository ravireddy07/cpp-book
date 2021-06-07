// Problem Statement: https://leetcode.com/problems/perfect-number/

#include <bits/stdc++h>
using namespace std;

class Solution
{
public:
    vector<int> divisors(int x)
    {
        vector<int> result;
        int i = 1;
        while (i * i <= x)
        {
            if (x % i == 0 && i != x)
            {
                result.push_back(i);
                if (x / i != i && x / i != x)
                    result.push_back(x / i);
            }
            i++;
        }
        return result;
    }
    bool checkPerfectNumber(int num)
    {
        vector<int> factors = divisors(num);
        long long sum = 0;
        for (auto &x : factors)
            sum += x;
        return (sum == num && num != 0);
    }
};

int main()
{
    Solution a;
    cout << a.checkPerfectNumber(28) << "\n";
    return 0;
}
