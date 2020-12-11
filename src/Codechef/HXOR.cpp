// Problem Statement:  https://www.codechef.com/DEC20B/problems/HXOR/

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

/*
1
5 11
1 1 1 1 1
0 0 0 0 1

1
2 11
1 1
0 0

1
3 8
1 29 16
0 0 12

1 
7 5
2 5 6 7 5 9 1
0 0 0 0 1 9 3

1 
7 2000948
2 5 6 7 5 9 1
0 0 0 0 0 0 11

1 
2 21
4 3
0 7
0 7

1
2 22
4 3
1 6
*/

const int p[] = {1, 2, 4, 8, 16, 32, 64, 128,
                 256, 512, 1024, 2048, 4096, 8192,
                 16384, 32768, 65536, 131072, 262144,
                 524288, 1048576, 2097152, 4194304,
                 8388608, 16777216, 33554432, 67108864,
                 134217728, 268435456, 536870912};

ll xorValue(ll a, ll b)
{
    return (a | b) & (~a | ~b);
}

ll choice(ll a)
{
    ll cnt = 0;
    while (a > 0)
    {
        cnt++;
        a /= 2;
    }
    if (cnt == 0)
        return 1;
    return cnt;
}

void test()
{
    ll n, x;
    scanf("%lld%lld", &n, &x);
    ll v[n];
    for (int i = 0; i < n; ++i)
        scanf("%lld", &v[i]);

    ll k = 0, j = 0;
    if (n == 2)
    {
        while (v[0] != 0 & x-- > 0)
        {
            k = choice(v[0]);
            v[0] = xorValue(v[0], p[k - 1]);
            v[1] = xorValue(v[1], p[k - 1]);
            /*for (int a = 0; a < n; a++)
                cout << v[a] << " ";
            cout << endl;*/
        }
        if (x > 0 && x % 2 == 0)
        {
            v[0] = 1;
            v[1] = v[1] ^ 1;
        }
    }
    else
    {
        for (int i = 0; i < n - 1;)
        {
            if (x == 0)
                break;
            if (v[i] != 0)
            {
                x--;
                k = choice(v[i]);
                v[i] = v[i] ^ p[k - 1];
                if (v[i + 1] < (v[i + 1] ^ p[k - 1]))
                {
                    j = i + 1;
                    while ((j + 1) < n && v[++j] < (v[j] ^ p[k - 1]))
                        ;
                    if (j == n)
                        v[n - 1] = (v[n - 1] ^ p[k - 1]);
                    else
                        v[j] = (v[j] ^ p[k - 1]);
                }
                else
                    v[i + 1] = (v[i + 1] ^ p[k - 1]);
            }
            else
                i++;
            // cout << "Hello" << endl;
            /*for (int a = 0; a < n; a++)
                cout << v[a] << " ";
            cout << endl;*/
        }
    }

    for (int i = 0; i < n; i++)
        printf("%lld ", v[i]);
    printf("\n");
    return;
}

/*
void test()
{
    ll n, x;
    scanf("%lld%lld", &n, &x);
    int temp[n];
    int res[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp[i]);
        res[i] = temp[i];
    }
    int p;
    int i = 1;
    int j = i + 1;

    // 1 3 8 1 29 16
    for (int q = 0; q < x; q++)
    {
        p = pow(2, log2(max(temp[i - 1], temp[j - 1])));
        if (p < pow(2, log2(max(temp[i - 1], temp[j - 1]))))
            p += 1;
        //cout << i << " " << j << " " << p << endl;
        //cout << temp[i - 1] << " " << temp[j - 1] << " " << p << endl;

        temp[i - 1] = temp[i - 1] ^ (int)p;
        temp[j - 1] = temp[j - 1] ^ (int)p;
        int w = 0;
        while (1)
        {
            if (temp[w] < res[w])
            {
                copy(temp, temp + n, res);
                //cout << "chnage" << endl;
                break;
            }
            else if (temp[w] > res[w])
            {
                //cout << "no chnage" << endl;
                break;
            }
            else
                w++;
        }

        /*for (int a = 0; a < n; a++)
            cout << temp[a] << " " << res[a] << endl;
        cout << endl;
        //cout << temp[i - 1] << " " << temp[j - 1] << endl;

        // 28 0 16
        int c = 1;
        for (int ch = 0; ch < n; ++ch)
        {
            if (temp[ch] != 0 and c)
            {
                i = ch + 1;
                c = 0;
            }
            else if (temp[ch] != 0)
            {
                j = ch + 1;
                break;
            }
            if (i == n)
            {
                q = x;
                break;
            }
        }
    }
    for (int a = 0; a < n; a++)
        cout << temp[a] << " ";
    cout << endl;
    return;
} */

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        test();
    return 0;
}
