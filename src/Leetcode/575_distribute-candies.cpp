// Problem Statement: https://leetcode.com/problems/distribute-candies/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int distributeCandies(vector<int> candies)
    {
        int n = candies.size();
        set<int> s;
        for (int i = 0; i < candies.size(); i++)
        {
            s.insert(candies[i]);
            if (s.size() == (n / 2))
                return (n / 2);
        }
        return s.size();
    }
};

int main()
{
    Solution a;
    cout << a.distributeCandies({1, 1, 2, 2, 3, 3}) << "\n";
    return 0;
}
