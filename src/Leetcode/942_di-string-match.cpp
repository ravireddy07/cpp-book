// https://leetcode.com/problems/create-target-array-in-the-given-order/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> diStringMatch(string S)
    {
        int small = 0, large = S.size();
        vector<int> res;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == 'I')
            {
                res.push_back(small);
                small++;
            }
            else
            {
                res.push_back(large);
                large--;
            }
        }
        res.push_back(small);
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> show = a.diStringMatch("IDID");
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