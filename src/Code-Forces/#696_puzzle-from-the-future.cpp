// Problem Statement:  https://codeforces.com/contest/1474/problem/A

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
#define ii3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define ill(a) scanf("%lld", &a)
#define ill2(a, b) scanf("%lld%lld", &a, &b)
#define ill3(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)
#define for1(i, a, b) for (int i = a; i < b; ++i)
#define for2(i, a, b) for (int i = b; i >= a; --i)
#define vi vector<int>
#define vii vector<vector<int>>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define unmp unordered_map
#define pqi priority_queue<int>
#define pb push_back
#define sorta(a) sort(a.begin(), a.end())
#define sortd(a) sort(a.begin(), a.end(), greater<>())
#define sortr(a) sort(a.rbegin(), a.rend())
#define yes printf("YES\n")
#define no printf("NO\n")
using namespace std;

template <typename T, typename T1>
T amax(T &a, T1 b)
{
    if (b > a)
        a = b;
    return a;
}


/*
a = 110
b = 100
d = 210

a = 011
b = 110
d = 121

111000
101101
212101

001011
101110
102121
*/

void harry() {
    int n;
    ii(n);
    string a = "", b, d = "";
    cin >> b;
    for1(i, 0, n) {
        if (!i and b[i] == '1') {
            a += '1';
            d += '2';
        }
        else if (!i and b[i] == '0') {
            a += '1';
            d += '1';
        }
        else if (b[i] == '1') {
            if (d[i - 1] == '0') {
                a += '1';
                d += '2';
            }
            else if (d[i - 1] == '1') {
                a += '1';
                d += '2';
            }
            else {
                a += '0';
                d += '1';
            }
        }
        else if (b[i] == '0') {
            if (d[i - 1] == '1') {
                a += '0';
                d += '0';
            }
            else if (d[i - 1] == '0') {
                a += '1';
                d += '1';
            }
            else {
                a += '1';
                d += '1';
            }
        }
    }
    cout << a << "\n";
    ravireddy07;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    ii(t);
    while (t--)
        harry();
    return 0;
}
