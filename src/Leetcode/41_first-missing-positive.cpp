// Problem Statement: https://leetcode.com/problems/first-missing-positive/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int count = 1, found = 1;
        while (1)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == count)
                    count++;
            }

            if (count == found)
                return count;
            else
                found = count;
        }
        return 0;
    }
};

int main()
{
    Solution a;
    vector<int> in = {3, 4, -1, 1};
    cout << a.firstMissingPositive(in) << "\n";
    return 0;
}
