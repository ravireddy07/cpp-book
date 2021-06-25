// Problem Statement: https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> alertNames(vector<string> name, vector<string> time)
    {
        if (name.size() < 3)
            return {};

        unordered_map<string, vector<int>> list;
        for (int i = 0; i < name.size(); ++i)
            list[name[i]].push_back(transfer(time[i]));

        vector<string> res;
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            vector<int> temp = it->second;
            if (temp.size() < 3)
                continue;

            sort(temp.begin(), temp.end());
            for (int i = 0; i < temp.size() - 2; ++i)
            {
                if (temp[i + 2] - temp[i] <= 60)
                {
                    res.push_back(it->first);
                    break;
                }
            }
        }

        sort(res.begin(), res.end());
        return res;
    }

    int transfer(string &str)
    {
        int res = 0;
        res += ((str[0] - '0') * 10 + (str[1] - '0')) * 60;
        res += ((str[3] - '0') * 10 + (str[4] - '0'));
        cout << res << " ";
        return res;
    }
};

int main()
{
    Solution a;
    vector<string> show = a.alertNames({"daniel", "daniel", "daniel", "luis", "luis", "luis", "luis"}, {"10:00", "10:40", "11:00", "09:00", "11:00", "13:00", "15:00"});

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
