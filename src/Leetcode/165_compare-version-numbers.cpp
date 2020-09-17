// https://leetcode.com/problems/compare-version-numbers/

#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> split(string &version1)
    {
        vector<int> splitted;
        if (version1.size() == 0)
            return splitted;
        int temp = 0;
        for (char c : version1)
        {
            if (c == '.')
            {
                splitted.push_back(temp);
                temp = 0;
            }
            else
                temp = temp * 10 + c - '0';
        }
        splitted.push_back(temp);
        return splitted;
    }

public:
    int compareVersion(string version1, string version2)
    {
        vector<int> v1 = split(version1);
        vector<int> v2 = split(version2);
        int minLen = min(v1.size(), v2.size());
        for (int i = 0; i < minLen; i++)
        {
            if (v1[i] > v2[i])
                return 1;
            if (v1[i] < v2[i])
                return -1;
        }
        for (int i = minLen; i < v1.size(); i++)
            if (v1[i] > 0)
                return 1;
        for (int i = minLen; i < v2.size(); i++)
            if (v2[i] > 0)
                return -1;
        return 0;
    }
};

int main()
{
    Solution a;
    cout << a.compareVersion("0.1", "1.1") << endl;
    return 0;
}
