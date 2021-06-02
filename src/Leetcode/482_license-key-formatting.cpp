// Problem Statement: https://leetcode.com/problems/license-key-formatting/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string licenseKeyFormatting(string str, int K)
    {
        vector<char> chVec;
        for (auto &ch : str)
            if (ch != '-' || islower(ch))
            {
                ch = toupper(ch);
                chVec.push_back(ch);
            }

        int sz = chVec.size();
        if (K >= sz)
        {
            string strReturn(chVec.begin(), chVec.end());
            return strReturn;
        }

        int firstPos = sz % K;
        if (firstPos == 0)
        {
            int segments = sz / K;
            firstPos = sz / segments;
        }

        vector<char> temp;
        int index = 1;
        bool bFirstDashDone = false;

        for (auto &x : chVec)
        {
            temp.push_back(x);
            if (index == firstPos && !bFirstDashDone)
            {
                temp.push_back('-');
                bFirstDashDone = true;
                index = 0;
            }
            else if (bFirstDashDone && index == K)
            {
                temp.push_back('-');
                index = 0;
            }
            index++;
        }

        if (temp[temp.size() - 1] == '-')
            temp.pop_back();
        std::string strReturn(temp.begin(), temp.end());
        return strReturn;
    }
};

int main()
{
    Solution a;
    cout << a.licenseKeyFormatting("5F3Z-2e-9-w", 4) << "\n";
    return 0;
}
