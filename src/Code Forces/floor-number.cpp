#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t)
    {
        int n, x;
        cin >> n >> x;
        int currPos = 2;
        int floor = 1;
        while (currPos < n)
        {
            floor += 1;
            currPos += x;
        }
        cout << floor << endl;
        t--;
    }
    return 0;
}