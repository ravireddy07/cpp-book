// https://leetcode.com/problems/combination-sum-iii/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(int n, int k, vector<vector<int>> &ans, vector<int> &sub)
    {
        if (sub.size() > k)
            return;
        if (n == 0 && sub.size() == k)
        {
            ans.push_back(sub);
            return;
        }
        for (int i = sub.empty() ? 1 : sub.back() + 1; i <= 9; ++i)
        {
            sub.push_back(i);
            if (n - i >= 0)
                dfs(n - i, k, ans, sub);
            sub.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> sub;
        dfs(n, k, ans, sub);
        return ans;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> output = a.combinationSum3(3, 7);
    return 0;
}