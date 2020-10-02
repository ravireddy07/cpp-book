// https://www.codechef.com/OCT20B/problems/CHEFEZQ
/*
#include <bits/stdc++.h>
using namespace std;

void test()
{
    int n, k;
    //scanf("%d%d", &n, &k);
    cin >> n >> k;
    vector<int> q(n);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        //scanf("%d", &q[i]);
        cin >> q[i];
        sum += q[i];
    }
    cout << sum / k + 1 << endl;
    return;
}

void test1()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    int rem = 0;
    int days = 1;
    for (int i = 0; i < n; ++i)
    {
        rem += v[i] - k;
        if (rem < 0)
        {
            cout << days << endl;
            return;
        }
        days++;
    }
    cout << days + (rem / k) << endl;
}

// https://www.codechef.com/OCT20B/problems/CHEFEZQ
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int v[n];
        for (int i = 0; i < n; ++i)
            cin >> v[i];

        int rem = 0;
        int days = 1;
        for (int i = 0; i < n; ++i)
        {
            rem += v[i] - k;
            if (rem < 0)
            {
                cout << days << endl;
                return;
            }
            days++;
        }
        cout << days + (rem / k) << endl;
    }
    return 0;
}