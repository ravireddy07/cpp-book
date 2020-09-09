#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
int main()
{
    int t, n;
    cin >> t;
    while (t > 0)
    {
        t -= 1;
        cin >> n;
        int ar[n][n], count = 0, done = 0, don = 0, temp;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> ar[i][j];

        for (int d = n - 1; d >= 0; --d)
        {
            done = ar[d][d - 1] + 1;
            if (done != ar[d][d])
            {
                count += 1;
                don = d + 1;
                for (int i = 0; i < don; i++)
                {
                    for (int j = i; j < don; j++)
                    {
                        temp = ar[i][j];
                        ar[i][j] = ar[j][i];
                        ar[j][i] = temp;
                    }
                }
            }
        }
        cout << count << endl;
    }
}