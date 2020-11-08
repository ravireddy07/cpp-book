// https://leetcode.com/problems/convert-a-number-to-hexadecimal/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string toHex(int num)
    {
        if (num == 0)
            return "0";
        const long long temp = pow(2, 32);
        long long n = (temp + num) % temp;
        string hex;
        unordered_map<int, char> hexCodes;
        for (int i = 0; i <= 15; ++i)
        {
            if (i < 10)
                hexCodes[i] = i + '0';
            else
                hexCodes[i] = 87 + i;
        }
        while (n)
        {
            char dig = n % 16;
            hex = hexCodes[dig] + hex;
            n /= 16;
        }
        return hex;
    }
};

int main()
{
    Solution a;
    cout << a.toHex(26) << endl;
    return 0;
}
