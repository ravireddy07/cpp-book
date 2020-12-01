// Problem Statement: https://codeforces.com/contest/1455/problem/D/

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool checkSort(vector<int> v)
{
    if (v.size() == 2)
    {
        if (v[0] > v[1])
            return 0;
    }
    else
    {
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] < v[i - 1])
                return 0;
        }
    }
    return 1;
}

/*                              res
    81 324 218 413 324   x=18
    18 324 218 413 324   x=81    1
    18 81  218 413 324   x=324   2
    18 81  218 413 324   x=324   2
    18 81  218 324 324   x=413   3
*/

void test()
{
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> v(n);
    int in;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &in);
        v.push_back(in);
    }
    int res = 0;
    bool sorted = false;
    int i = 0, prev = 0;
    do
    {
        if (v[i] < x and prev > v[i])
        {
            res = -1;
            sorted = 1;
        }
        else if (v[i] > x)
        {
            swap(v[i], x);
            res++;
        }
        else if (checkSort(v))
        {
            sorted = 1;
            break;
        }
        i++;
        prev = v[i];
    } while (!sorted and i != v.size());

    if (!sorted)
        printf("-1\n");
    else
        printf("%d\n", res);
    return;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        test();
    return 0;
}
