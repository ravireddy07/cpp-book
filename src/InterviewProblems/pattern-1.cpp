/*
Required Pattern:

n = 5

1 
2 6
3 7 10
4 8 11 13
5 9 12 14 15

*/

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int n = 5, num = 1;
    int col = n - 1; // reverse col count
    for (int i = 0; i < n; i++)
    {
        col = n - 1;
        num = i + 1;
        if (i == 0)
        {
            cout << num;
            num++;
        }
        else
        {
            cout << num << " ";
            for (int j = 0; j < i; j++)
            {
                cout << num + col << " ";
                num += col;
                col--;
            }
            num++;
        }
        cout << endl;
    }
    return 0;
}
