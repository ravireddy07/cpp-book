// Problem Statement: https://leetcode.com/problems/plus-one/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int i, m;
        for (i = digits.size() - 1; i >= 0; i--)
        {
            m = digits[i] + 1;
            if (m < 10)
            {
                digits[i] = m;
                break;
            }
            else
                digits[i] = m % 10;
        }

        if (i == -1 && m > 9)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main()
{
    Solution a;
    vector<int> input = {1, 2, 3};
    vector<int> show = a.plusOne(input) << "\n";
    cout << "[";
    for (int i = 0; i < show.size(); i++)
    {
        if (i == show.size() - 1)
            cout << show[i];
        else
            cout << show[i] << ", ";
    }
    cout << "]";
    return 0;
}
