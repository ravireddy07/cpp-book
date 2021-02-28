// Problem Statement: https://leetcode.com/problems/count-primes/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));
        for (int p = 2; p * p < n; p++)
            if (prime[p] == true)
                for (int i = p * p; i < n; i += p)
                    prime[i] = false;

        int cnt = 0;
        for (int p = 2; p < n; p++)
            if (prime[p])
                cnt += 1;
        return cnt;
    }
};

int main()
{
    Solution a;
    cout << a.countPrimes(10) << endl;
    return 0;
}
