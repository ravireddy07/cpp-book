// Problem Statement: https://leetcode.com/problems/remove-duplicate-letters/
// Not solved

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> list;
    string removeDuplicateLetters(string s)
    {
        string ans = "";
        string res = "";
        for (int i = 0; i < s.size(); i++)
        {
            int it = ans.find(s[i]);
            if (it == -1)
                ans += s[i];
        }

        getPrem(ans, 0, ans.size() - 1);
        int k, max = INT_MAX, c = 0;
        vector<string> f;
        for (int i = 0; i < list.size(); i++)
        {
            string temp = list[i];
            k = 0;
            for (int j = 0; j < s.size(); j++)
            {
                if (s[j] == temp[k])
                {
                    if (k == temp.size() - 1)
                    {
                        c = 0;
                        for (int d = 1; d < temp.size(); d++)
                        {
                            if (temp[d] < temp[d - 1])
                            {
                                c++;
                            }
                        }
                        if (c < max)
                        {
                            max = c;
                            res = temp;
                            cout << c << " ";
                        }
                        break;
                        // [cbad, cadb, bacd, badc, acdb, adcb, adbc]
                    }
                    k++;
                }
            }
        }
        return res;
    }

    void getPrem(string a, int l, int r)
    {
        if (l == r)
        {
            list.push_back(a);
        }
        else
        {
            for (int i = l; i <= r; i++)
            {
                swap(a[l], a[i]);
                getPrem(a, l + 1, r);
                swap(a[l], a[i]);
            }
        }
        return;
    }
};

int main()
{
    Solution a;
    cout << a.removeDuplicateLetters("cbacdcbc") << "\n";
    return 0;
}
