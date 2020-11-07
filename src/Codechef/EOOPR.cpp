// https://www.codechef.com/problems/EOOPR

#include <iostream>
#define ll long long int
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        if (x == y)
            cout << 0 << endl;
        else if (x < y)
        {
            if ((y - x) % 2 == 0 && ((y - x) / 2) % 2 != 0)
                cout << 2 << endl;
            else if ((y - x) % 2 == 0)
                cout << 3 << endl;
            else
                cout << 1 << endl;
        }
        else
        {
            if ((x - y) % 2 == 0)
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
    }
    return 0;
}
