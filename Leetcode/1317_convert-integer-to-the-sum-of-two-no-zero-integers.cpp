// https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    bool noz(int n)
    {
        while (n)
        {
            int t = n % 10;
            n /= 10;
            if (!t)
                return false;
        }
        return true;
    }

public:
    vector<int> getNoZeroIntegers(int n)
    {
        for (int i = n - 1; i >= n / 2; i--)
            if (i + (n - i) == n && noz(i) && noz(n - i))
                return vector<int>{n - i, i};
        return vector<int>{};
    }
};

int main()
{
    Solution a;
    vector<int> show = a.getNoZeroIntegers(2);
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