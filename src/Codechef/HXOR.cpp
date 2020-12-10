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

1
2 22
4 3
1 6
*/

void test()
{
    ll n, x;
    scanf("%lld%lld", &n, &x);
    int temp[n];
    int v[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        temp[i] = v[i];
    }
    int p;
    int i = 1;
    int j = i + 1;

    // 1 3 8 1 29 16
    for (int q = 0; q < 2; q++)
    {
        p = pow(2, log2(max(temp[i - 1], temp[j - 1]))) + 1;
        //cout << temp[i - 1] << " " << temp[j - 1] << " " << p << endl;

        temp[i - 1] = temp[i - 1] ^ p;
        temp[j - 1] = temp[j - 1] ^ p;

        cout << i << " " << j << endl;
        for (int a = 0; a < n; a++)
            cout << temp[a] << " ";
        cout << endl;
        //cout << temp[i - 1] << " " << temp[j - 1] << endl;

        for (int ch = 0; ch < n; ch++)
        {
            bool cnt = 1;
            if (temp[i] != 0 and cnt)
            {
                i = ch + 1;
                cnt = 0;
            }
            else if (temp[i] != 0 and !cnt)
                j = ch + 1;
        }
    }
    for (int a = 0; a < n; a++)
        cout << temp[a] << " ";
    cout << endl;
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
