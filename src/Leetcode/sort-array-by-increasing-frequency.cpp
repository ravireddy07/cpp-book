// https://leetcode.com/problems/sort-array-by-increasing-frequency/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> frequencySort(vector<int> a)
    {
        map<int, int> cnt;
        for (int i : a)
            cnt[i]++;
        sort(a.begin(), a.end(), [&](int x, int y) {
            make_pair(cnt[x], -x) < make_pair(cnt[y], -y);
        });
        return a;
    }
};

int main()
{
    Solution a;
    vector<int> in = {1, 2, 3, 2, 1, 1, 4, 4};
    vector<int> show = a.frequencySort(in);
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
