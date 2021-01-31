// Problem Statement: https://www.codechef.com/DEC20B/problems/STROPERS/

#include <bits/stdc++.h>
#define ll long long int
#define pii pair<ll, ll>
using namespace std;

/*
10001
output: 11

00000
0 00 000 0000 00000
5

10101

class
  1    1           0           1       0       1
  2    10          01          10      01
  2    101         010         101
  1    1010        0101
  1    10101       

Out: 8

01111

2    0          1       1       1       1
2    01         11      11      11
2    011        111     111
2    0111       1111
1    01111

9

11001
12

01101
10

10110
2    1     0    1   1   0
3    10    01   11  10
2    101   011  110
2    1011  0110
1    10110
10

10010
11

10111
11

11001
12
*/

/*
// Unaccepted Solution(only Base solved)
bool ff(set<string> res, string s)
{
    for (auto i : res)
        if (i == s)
            return 0;
    return 1;
}

void test()
{
    string s;
    cin >> s;
    set<string> res;
    vector<string> list;
    string temp = "";

    for (int i = 0; i < s.size(); ++i)
    {
        temp = s[i];
        list.push_back(temp);
        for (int j = i + 1; j < s.size(); ++j)
        {
            temp += s[j];
            list.push_back(temp);
        }
    }

    int cnt = 0;
    temp = "";
    for (int i = 0; i < list.size(); i++)
    {
        cnt = 0;
        temp = list[i];
        for (int j = 0; j < temp.size(); ++j)
            if (temp[j] == '1')
                cnt++;

        if (cnt % 2 == 0)
            reverse(temp.begin(), temp.end());
        if (ff(res, temp))
            res.insert(list[i]);
    }

    cout << res.size() << endl;
    return;
}
*/

// Accepted Solution
void test()
{
    string s;
    cin >> s;
    set<pair<pii, int>> res;

    ll n = s.size();
    for (int i = 0; i < n; ++i)
    {
        ll ev = 0, dod = 0, var = 0;
        for (ll j = i; j < n; ++j)
        {
            if (s[j] == char(49))
                var++;
            else
            {
                if (var & 1)
                    dod++;
                else
                    ev++;
            }
            res.insert({{ev, dod}, var});
        }
    }

    cout << res.size() << endl;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        test();
    return 0;
}
