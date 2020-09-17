// https://leetcode.com/problems/longest-harmonious-subsequence/

#include <iostream>
using namespace std;

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        unordered_map<int, int> um;
        for (int &x : nums)
            um[x]++;
        int ans = 0;
        for (auto itr = um.begin(); itr != um.end(); itr++)
        {
            int x = itr->first;
            if (um.count(x + 1))
            {
                int count = itr->second + um[x + 1];
                ans = max(ans, count);
            }
        }
        return ans;
    }
};

int main()
{
    Solution a;
    vector<int> input = {1, 3, 2, 2, 5, 2, 3, 7};
    cout << a.findLHS(input) << endl;
    return 0;
}