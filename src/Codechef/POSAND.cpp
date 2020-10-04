// https://www.codechef.com/OCT20B/problems/POSAND

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int power(int p)
{
    return p != 0 && ((p & (p - 1)) == 0);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        else if (n == 3)
        {
            cout << 1 << " " << 3 << " " << 2 << endl;
            continue;
        }
        else if (n == 5)
        {
            cout << 2 << " " << 3 << " " << 1 << " " << 5 << " " << 4 << endl;
            continue;
        }
        else if (power(n))
        {
            cout << -1 << endl;
            continue;
        }
        else
        {
            cout << 2 << " " << 3 << " " << 1 << " " << 5 << " " << 4 << endl;
            int i = 6;
            while (i <= n)
            {
                if (power(i))
                {
                    cout << i + 1 << " " << i << " ";
                    i += 2;
                }
                else
                {
                    cout << i << " ";
                    i++;
                }
            }
            cout << endl;
        }
    }
    return 0;
}