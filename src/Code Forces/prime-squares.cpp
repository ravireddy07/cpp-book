// https://codeforces.com/contest/1436/problem/B

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void test()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || i == j - 1 || i == j + 1)
            {
                cout << "1"
                     << " ";
            }
            else
            {
                cout << "0"
                     << " ";
            }
        }
        cout << endl;
    }
    /*
    1 1 0 0 0
    1 1 1 0 0
    0 1 1 1 0
    0 0 1 1 1
    0 0 0 1 1
    */
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