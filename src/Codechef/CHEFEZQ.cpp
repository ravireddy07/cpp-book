// https://www.codechef.com/OCT20B/problems/CHEFEZQ

#include <bits/stdc++.h>
using namespace std;

void test()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> q(n);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &q[i]);
        sum += q[i];
    }

    double res = sum / k;
    cout << (int)res + 1 << endl;
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        test();
    }
    return 0;
}