// Problem Statement : https://www.codechef.com/ENNO2020/problems/ENCDNOV

#include <bits/stdc++.h>
#define lli long long int
using namespace std;

void test1()
{
    int n;
    scanf("%d", &n);
    vector<int> vv;
    int v[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        vv.push_back(v[i]);
    }
    int res = 0, temp = 0;
    sort(vv.begin(), vv.end());
    for (int i = 0; i < n; i++)
    {
        if (v[i] != vv[i])
        {
            if (temp > 0)
            {
                res += temp;
                temp = 0;
            }
            res++;
        }
        else if (v[i] == vv[i] and res > 0)
            temp++;
    }
    cout << res << endl;
}
// 1 2 3 6 3 5 1 8 9
// 1 1 2 3 3 5 6 8 9

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        test1();
    return 0;
}
