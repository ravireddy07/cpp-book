// https://leetcode.com/problems/find-lucky-integer-in-an-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        int freq;
        int res = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            freq = 0;
            for (int j = 0; j < arr.size(); j++)
                if (arr[i] == arr[j])
                    freq++;
            if (freq == arr[i])
                res = max(arr[i], res);
        }
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> in = {2, 2, 2, 3, 3};
    cout << a.findLucky(in) << endl;
    return 0;
}