// https://leetcode.com/problems/count-unhappy-friends/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int unhappyFriends(int n, vector<vector<int>> &p, vector<vector<int>> &pairs)
    {
        int res = 0, d, v, count;
        vector<int> pairing(n);
        vector<vector<int>> friends(n, vector<int>(n));
        for (int i = 0; i < p.size(); ++i)
            for (int j = 0; j < p[i].size(); ++j)
                friends[i][p[i][j]] = j;

        for (auto &it : pairs)
            pairing[it[0]] = it[1], pairing[it[1]] = it[0];

        for (int i = 0; i < n; ++i)
        {
            count = 0;
            for (int j = 0; j < n; ++j)
                if (j != i && j != pairing[i])
                {
                    d = pairing[i], v = pairing[j];
                    if (friends[i][j] < friends[i][d] && friends[j][i] < friends[j][v])
                        count = 1;
                }
            res += count;
        }
        return res;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> input1 = {{1, 2, 3}, {3, 2, 0}, {3, 1, 0}, {1, 2, 0}};
    vector<vector<int>> input2 = {{0, 1}, {2, 3}};
    cout << a.unhappyFriends(4, input1, input2) << endl;
    return 0;
}