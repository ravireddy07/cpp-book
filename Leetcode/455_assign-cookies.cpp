// https://leetcode.com/problems/assign-cookies/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int result = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for (int i = 0, j = 0; i < s.size() and j < g.size();)
        {
            if (s[i] >= g[j])
            {
                result++;
                j++;
            }
            i++;
        }
        return result;
    }
};


int main()
{
    Solution a;
    vector<int> input1 = {1, 2, 3};
    vector<int> input2 = {1, 1};
    cout << a.findContentChildren(input1, input2) << endl;
    return 0;
}