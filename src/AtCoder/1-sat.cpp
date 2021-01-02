// Problem Statement: https://atcoder.jp/contests/abc187/tasks/abc187_c/

/**
 *  Author: Ravi Kanth Gojur
 *  Code Forces: ravireddy07
 *  Code Chef: ravireddy115
 *  Github: ravireddy07
**/

#include <bits/stdc++.h>
#define ll long long int
#define ravireddy07 return
#define ii(a) scanf("%d", &a)
#define ii2(a, b) scanf("%d%d", &a, &b)
#define ill(a) scanf("%lld", &a)
#define ill2(a, b) scanf("%lld%lld", &a, &b)
#define vi vector<int>
#define vii vector<vector<int>>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define pb push_back
#define sorta(a) sort(a.begin(), a.end())
#define sortd(a) sort(a.begin(), a.end(), greater<>())
#define sortr(a) sort(a.rbegin(), a.rend())
#define pqi priority_queue<int>
#define pq priority_queue
#define yes printf("YES")
#define no printf("NO")
using namespace std;
#

void harry()
{
    int n;
    ii(n);
    string a;
    map<string, int> v;
    vector<string> v1;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a[0] == '!')
        {
            a.erase(a.begin());
            v[a] = 1;
        }
        else
            v1.push_back(a);
    }

    for (int i = 0; i < v1.size(); i++)
    {
        if (v[v1[i]] == 1)
        {
            cout << v1[i] << "\n";
            return;
        }
    }
    cout << "satisfiable\n";
    ravireddy07;
}

int main()
{
    harry();
    return 0;
}
