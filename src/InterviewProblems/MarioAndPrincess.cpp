// https://skillenza.com/challenge/off-campus-hack-september

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ar[n];
        for (int i = 0; i < n; i++)
            cin >> ar[i];
        int max = 0;
        int countI = 1; // length of the path
        int countD = 1;

        //For Non-Increasing Path
        for (int i = 1; i < n; i++)
        {
            if (ar[i] >= ar[i - 1])
                countI++;
            else
            {
                if (countI > max)
                    max = countI;
                countI = 1;
            }
        }

        //For Non-Decreasing Path
        for (int i = 1; i < n; i++)
        {
            if (ar[i] <= ar[i - 1])
                countD++;
            else
            {
                if (countD > max)
                    max = countD;
                countD = 1;
            }
        }

        // Can use max fun() here
        if (countD > max)
            max = countD;
        if (countI > max)
            max = countI;
        cout << max << endl;
    }
    return 0;
}