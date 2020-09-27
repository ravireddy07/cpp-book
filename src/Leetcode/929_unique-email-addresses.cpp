// https://leetcode.com/problems/unique-email-addresses/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        set<string> res;
        for (int i = 0; i < emails.size(); ++i)
        {
            int count = 0;
            for (int j = 0; j < emails[i].length(); ++j)
            {
                if (emails[i][j] == '@')
                    break;
                else if (emails[i][j] == '.')
                {
                    emails[i].erase(j, 1);
                    --j;
                }
                else if (emails[i][j] == '+')
                {
                    count = j;
                    break;
                }
            }

            int pos = emails[i].find('@');
            if (count != 0)
                emails[i].erase(count, pos - count);
            res.insert(emails[i]);
        }
        return res.size();
    }
};

int main()
{
    Solution a;
    vector<string> in = {"test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com"};
    cout << a.numUniqueEmails(in) << endl;
    return 0;
}