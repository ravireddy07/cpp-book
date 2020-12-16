/*
Required Pattern:

n = 5, k = 3

1 2 3
6 5 4
7 8 9
12 11 10
13 14 15

*/

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int n = 5, k = 3, num = 1;
    int rev = 1;
    for (int i = 0; i < n; i++)
    {
        rev = rev ? 0 : 1;
        if (rev)
        {
            for (int j = k - 1; j >= 0; j--)
                cout << num + j << " ";
            num += k;
        }
        else
        {
            for (int j = 0; j < k; j++)
                cout << num++ << " ";
        }
        cout << endl;
    }
    return 0;
}
