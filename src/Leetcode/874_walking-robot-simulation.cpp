// Problem statement:  https://leetcode.com/problems/walking-robot-simulation/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> obstacles)
    {
        unordered_set<string> obst;
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0, x = 0, y = 0, res = 0;
        for (auto &v : obstacles)
            obst.insert(to_string(v[0]) + ":" + to_string(v[1]));
        for (auto c : commands)
        {
            if (c > 0)
            {
                while (c-- && obst.count(to_string(x + dirs[d][0]) + ":" + to_string(y + dirs[d][1])) == 0)
                {
                    x += dirs[d][0];
                    y += dirs[d][1];
                }
                res = max(res, x * x + y * y);
            }
            else if (c == -1)
                d = (d + 1) % 4;
            else if (c == -2)
                d = (d + 3) % 4;
        }
        return res;
    }
};

int main()
{
    Solution a;
    cout << a.robotSim({4, -1, 4, -2, 4}, {{2, 4}}) << "\n";
    return 0;
}
