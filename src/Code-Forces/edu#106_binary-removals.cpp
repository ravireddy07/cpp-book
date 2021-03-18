// Problem Statement: https://codeforces.com/contest/1499/problem/B

/**
 *  Author: Ravi Kanth Gojur
 *  Code Forces: ravireddy07
 *  Code Chef: ravireddy115
 *  Github: ravireddy07
**/

#include <bits/stdc++.h>
#define ll long long int
#define yes printf("YES\n")
#define no printf("NO\n")
using namespace std;

void harry()
{
    string str;
    cin >> str;
    int n = str.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == '1' && str[i + 1] == '1')
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                if (str[j] == '0' && str[j + 1] == '0')
                {
                    no;
                    return;
                }
            }
            break;
        }
    }
    yes;
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    while (t--)
        harry();
    return 0;
}
