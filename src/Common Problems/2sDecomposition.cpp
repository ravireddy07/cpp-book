/*
Sample Input:                 Sample Output:
26                            2 * 13

Sample Input:                 Sample Output:
7                             7

Sample Input:                 Sample Output:
72                            2 * 2 * 2 * 9

Sample Input:                 Sample Output:
424                           2 * 2 * 2 * 53
*/

#include <iostream>
using namespace std;

int main()
{
    int n = 424;
    //cin >> n;
    while (n % 2 == 0)
    {
        n = n / 2;
        cout << 2 << " * ";
    }
    cout << n;
    return 0;
}