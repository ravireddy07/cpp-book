// https://leetcode.com/problems/evaluate-division/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, vector<pair<string, double>>> g;
        for (int i = 0; i < equations.size(); ++i)
        {
            auto &e = equations[i];
            g[e[0]].push_back({e[1], values[i]});
            g[e[1]].push_back({e[0], 1 / values[i]});
        }

        vector<double> ans;
        for (auto &q : queries)
        {
            if (!g.count(q[0]) || !g.count(q[1]))
                ans.push_back(-1.0);
            else if (q[0] == q[1])
                ans.push_back(1.0);
            else
                ans.push_back(dfs(q[0], q[1], {}, g));
        }
        return ans;
    }

    double dfs(string &a, string &b, unordered_set<string> visited, unordered_map<string, vector<pair<string, double>>> &g)
    {
        if (visited.count(a))
            return -1.0;

        visited.insert(a);
        for (auto &p : g[a])
        {
            if (p.first == b)
                return p.second;

            double ret = dfs(p.first, b, visited, g);
            if (ret > 0)
                return p.second * ret;
        }
        return -1.0;
    }
};

int main()
{
    Solution a;
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}}, queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    vector<double> values = {{2.0}, {3.0}};
    vector<double> show = a.calcEquation(equations, values, queries);
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
