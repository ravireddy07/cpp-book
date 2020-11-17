// Problem Statement: https://www.codechef.com/NOV20B/problems/CNDYGAME
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void test()
{
    ll n;
    scanf("%lld", &n);
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &v[i]);
    ll q;
    scanf("%lld", &q);
    vector<ll> r(q);
    for (int i = 0; i < q; i++)
        scanf("%lld", &r[i]);

    //i-turn:   c = (a[i-1]%N)+1
    vector<ll> res = {0, 0};
    ll turn = 0, maxTurn = *max_element(r.begin(), r.end());
    int i = 0, j = 0, count = 0;
    for (i; count <= maxTurn; i++)
    {
        count++;
        if (count > r[j])
        {
            turn = turn ? 0 : 1;
            j++;
        }

        if (i > n)
            i %= n;

        if (i == n - 1)
        {
            if (v[i] % 2 == 0)
                res[turn] += v[i] - 1;
            else
                res[turn] += v[i];
        }
        else if (v[i + 1] == 1)
        {
            res[turn] += v[i];
            turn = turn ? 0 : 1;
        }
        else if (v[i] == 1)
        {
            res[turn] += v[i];
            turn = turn ? 0 : 1;
        }
        else if (v[i] > 1)
        {
            if (v[i] % 2 == 0)
                res[turn] += v[i];
            else
                res[turn] += v[i] - 1;
        }
    }
    printf("%lld\n", res[0]);
    return;
}

/*
4
5
2 4 1 6 8
3
2
3
5
5
3 5 1 6 7
3
2
3
5
5
1 2 3 4 5
3
1
6
7
5
2 3 4 5 1
3
15
16
17

Ans
6
7
19
7
7
20
1
1
2
39
41
44
*/
int main()
{
    int t;
    cin >> t;
    while (t--)
        test();
    return 0;
}
