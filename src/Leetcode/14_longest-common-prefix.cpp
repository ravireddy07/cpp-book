// https://leetcode.com/problems/longest-common-prefix/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> strs)
    {
        if (strs.size() == 0)
            return "";
        if (1 == strs.size())
            return strs[0];
        string temp = strs[0], result = "";
        int len = temp.size();
        bool over = false;
        for (int i = 0; i < len && !over; ++i)
        {
            char ch = temp[i];
            for (size_t k = 1; k < strs.size(); ++k)
            {
                if (strs[k].size() <= i || strs[k][i] != ch)
                {
                    over = true;
                    break;
                }
            }
            if (!over)
                result += ch;
        }
        return result;
    }
};

int main()
{
    Solution a;
    cout << a.longestCommonPrefix({"flower", "flow", "flight"}) << endl;
    return 0;
}
