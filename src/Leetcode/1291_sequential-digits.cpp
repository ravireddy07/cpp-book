// https://leetcode.com/problems/sequential-digits/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> res;
    void generate(int num, int digit, int low, int high)
    {
        if (num >= low && num <= high)
            res.push_back(num);
        if (digit > 9)
            return;
        num = num * 10 + digit;
        generate(num, digit + 1, low, high);
    }
    vector<int> sequentialDigits(int low, int high)
    {
        for (int i = 1; i <= 9; i++)
        {
            generate(0, i, low, high);
        }
        sort(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> show = a.sequentialDigits(100, 300);
    cout << "[";
    for (int i = 0; i < show.size(); i++)
    {
        if (i == show.size() - 1)
            cout << show[i];
        else
            cout << show[i] << ", ";
    }
    cout << "]" << endl;
    return 0;
}