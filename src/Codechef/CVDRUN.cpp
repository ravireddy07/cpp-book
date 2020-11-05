// https://www.codechef.com/OCT20B/problems/CVDRUN

#include <bits/stdc++.h>
using namespace std;

void test()
{
    int n, k, x, y;
    scanf("%d%d%d%d", &n, &k, &x, &y);
    vector<int> v;

    int d = x;
    do
    {
        vector<int>::iterator it = find(v.begin(), v.end(), d);
        if (d == y)
        {
            cout << "YES\n";
            break;
        }
        else if (it != v.end())
        {
            cout << "NO\n";
            break;
        }
        else
        {
            v.push_back(d);
            d = (d + k) % n;
        }
    } while (1);
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        test();
    return 0;
}
