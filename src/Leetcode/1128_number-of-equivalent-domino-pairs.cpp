// https://leetcode.com/problems/number-of-equivalent-domino-pairs/

#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        int res = 0;
        for (int i = 0; i < dominoes.size(); i++)
            for (int j = i + 1; j < dominoes.size(); j++)
                if (dominoes[i][0] == dominoes[j][1] && dominoes[i][1] == dominoes[j][0] || dominoes[i][0] == dominoes[j][0] && dominoes[i][1] == dominoes[j][1])
                    res++;
        return res;
    }
};

class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        map<pair<int, int>, int> seen;
        int result = 0;
        for (auto &v : dominoes)
        {
            if (v[0] > v[1])
                swap(v[0], v[1]);
            seen[make_pair(v[0], v[1])]++;
        }
        for (auto &[key, value] : seen)
            result += value * (value - 1) / 2;
        return result;
    }
};
*/
class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        map<pair<int, int>, int> seen;
        int result = 0;
        for (auto &v : dominoes)
        {
            if (v[0] > v[1])
                swap(v[0], v[1]);
            result += seen[make_pair(v[0], v[1])]++;
        }
        return result;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> input = {{1, 2}, {1, 2}, {1, 1}, {1, 2}, {2, 2}};
    cout << a.numEquivDominoPairs(input) << endl;
    return 0;
}