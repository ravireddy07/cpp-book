// https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period
#include <bits/stdc++.h>
using namespace std;

/*
// Brute Force (35/77)
class Solution
{
public:
    vector<string> alertNames(vector<string> &keyName, vector<string> &keyTime)
    {
        vector<string> res;
        vector<int> time(keyTime.size());
        int count, s, e;
        for (int i = 0; i < keyName.size(); i++)
            time[i] = stoi(keyTime[i].substr(0, 2) + keyTime[i].substr(3, 2));

        for (int i = 0; i < keyName.size() - 1; i++)
        {
            if (i && count >= 3 && keyName[i] == keyName[i - 1])
                continue;
            count = 1;
            s = time[i];
            for (int j = i + 1; j < keyName.size(); j++)
            {
                if (keyName[i] == keyName[j])
                {
                    if (abs(time[j] - s) <= 100)
                    {
                        count++;
                        e = time[j];
                        if (count >= 3)
                            res.push_back(keyName[i]);
                    }
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
*/

class Solution
{
public:
    vector<string> alertNames(vector<string> &name, vector<string> &time)
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
    vector<string> in1 = {"daniel", "daniel", "daniel", "luis", "luis", "luis", "luis"},
                   in2 = {"10:00", "10:40", "11:00", "09:00", "11:00", "13:00", "15:00"};

    vector<string> show = a.alertNames(in1, in2);

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