// https://leetcode.com/problems/self-dividing-numbers/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> candidate;
        for (int n = left; n <= right; n++)
        {
            int temp = n;
            while (temp > 0)
            {
                int digit = temp % 10;
                if (digit == 0 || n % digit != 0)
                    break;
                temp /= 10;
            }
            if (temp == 0)
                candidate.push_back(n);
        }
        return candidate;
    }
};

int main()
{
    Solution a;
    vector<int> show = a.selfDividingNumbers(128);
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