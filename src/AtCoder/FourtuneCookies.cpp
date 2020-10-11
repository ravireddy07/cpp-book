#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == b + c + d)
        cout << "Yes" << endl;
    else if (b == a + c + d)
        cout << "Yes" << endl;
    else if (c == b + a + d)
        cout << "Yes" << endl;
    else if (d == b + c + a)
        cout << "Yes" << endl;
    else if (a + b == c + d)
        cout << "Yes" << endl;
    else if (c + a == b + d)
        cout << "Yes" << endl;
    else if (c + b == d + a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}