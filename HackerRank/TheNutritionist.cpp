/*
Sample Input:                 Sample Output:             Explanation:
4                             9                          2+3+4 = 9
1 2 3 4                                                  1+3+4 = 8
                                                         1+2+4 = 7
                                                         Since, 2+3+4=9 gives the maximum number.


Sample Input:                 Sample Output:             Explanation:
2                            3                          1+2 = 3
2


Sample Input:                 Sample Output:             Explanation:
2                             2                          We cannot use 1, because k=1, and sum = k(unhealthy)
1                                                        0+2 = 2



Sample Input:                 Sample Output:             Explanation:
3                             5                          2+3 = 5
3

*/

#include <iostream>
#define ll long long int
using namespace std;

int result = 0, unhealthy = 0;

// Method - 1
int main()
{
    long int n, k;
    double val = 0;
    ll sum = 0;

    cin >> n >> k;

    val = sqrt(8 * k + 1);

    sum = n * (n * 1) / 2;

    if (val floor(val) == 0)
    {
        sum -= 1;
    }

    cout << sum << endl;
}

// Method - 2
int findComb(int items, int size)
{
    ll total = 1 << 0;

    for (ll i = 0; i < total; i++)
    {
        ll sum = 0;
        for (ll j = 0; j < s; j++)
        {
            sum += items[j];
        }
        if (result < sum && unhealthy != sum)
        {
            result = sum;
        }
    }
    return result;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int items[n];
    for (int i = 0; i < n; i++)
    {
        if (k == 1)
        {
            items[i] = 0;
        }
        else
        {
            items[i] = i + 1;
        }
    }

    if (n > 2)
    {
        for (int i = 0; i < n; i++)
        {
            unhealthy += items[i];
        }
    }

    int s = sizeof(items) / sizeof(items[0]);
    result = findComb(items, s);
    cout << result << endl;

    return 0;
}