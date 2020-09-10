#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> ar(n);
        fill(ar.begin(), ar.end(), 0);
        for (int i = 0; i < n; ++i)
        {
            cin >> ar[i];
        }
        int t = 0, best = 0, temp, worst = 0;
        for (int i = 1; i <= 4; ++i)
        { // i == position
            for (int j = 0; j < ar.size(); j++)
            {
                ar[j] = i + ar[j] * t;
            }
            t++;
            if (max_element(ar.begin(), ar.end()) == min_element(ar.begin(), ar.end()))
            {
                worst = ar.size();
                cout << worst << endl;
                return 0;
            }
            temp = ar[0];
            for (int k = 1; k < ar.size(); k++)
            {
                if (temp == ar[k] && best == 0)
                {
                    best += 1;
                }
                else
                {
                    worst += 1;
                }
            }
        }
    }
    return 0;
}
