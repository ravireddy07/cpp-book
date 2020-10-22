// https://leetcode.com/problems/check-if-string-is-transformable-with-substring-sort-operations/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isTransformable(string s, string t)
    {
        string a = s, b = t;
        int i, k, n = s.length();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a != b)
            return false;
        set<int> x[10];
        for (i = 0; i < n; i++)
            x[s[i] - '0'].insert(i);
        for (i = 0; i < n; i++)
        {
            auto it = x[t[i] - '0'].lower_bound(0);
            for (k = 0; k < (t[i] - '0'); k++)
                if ((int)(x[k].size()) != 0 && (*x[k].begin()) < (*it))
                    return false;
            x[t[i] - '0'].erase(*it);
        }
        return true;
    }
};

int main()
{
    Solution a;
    cout << a.isTransformable("84532", "34852");
    return 0;
}