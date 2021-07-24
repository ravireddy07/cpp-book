// Problem Statement: https://leetcode.com/problems/defuse-the-bomb

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> decrypt(vector<int> code, int k)
    {
        vector<int> res(code.size(), 0);
        int it; // count of k values while doing sum
        if (k == 0)
            return res;
        else
        {
            for (int i = 0; i < code.size(); i++)
            {
                it = 0;
                if (k > 0)
                {
                    for (int j = i + 1; it < k; j++)
                    {
                        if (j == code.size())
                            j = 0;
                        res[i] += code[j];
                        it++;
                    }
                }
                else if (k < 0)
                {
                    for (int j = i - 1; it > k; j--)
                    {
                        if (j < 0)
                            j = code.size() - 1;
                        res[i] += code[j];
                        it--;
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> show = a.decrypt({5, 7, 1, 4}, 3);
    cout << "[";
    for (int i = 0; i < show.size(); i++)
    {
        if (i == show.size() - 1)
            cout << show[i];
        else
            cout << show[i] << ", ";
    }
    cout << "]"
         << "\n";
    return 0;
}
