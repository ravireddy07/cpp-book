/*      Problem Statement

Given two relatively large numbers, A and B.
We need to compute (a^b) % 1000000007.

Input:

The first line of input contains a single integer T.
Each of the next T lines contain two integers A and B.

Output:

Calculate the value of the given expression.


Sample Input:                  Sample Output:
2
10 10                          999999937
1000000 10                     648999181
*/

#include <iostream>
#define ll long long int
using namespace std;

ll simple(ll a, ll b)
{
    ll result = 1;
    if (b == 0)
    {
        return 1;
    }
    else if (b > 0)
    {
        result = a * simple(a, b - 1);
    }
    else
    {
        return 1;
    }
    return (result % 1000000007);
}

int main()
{
    ll t, a, b, output;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        output = simple(a, b);
        cout << output << endl;
    }
    return 0;
}