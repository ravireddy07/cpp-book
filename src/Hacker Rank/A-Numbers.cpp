/*

Input:
contains one integer number A(3 <= A <= 1000).

Output:
Output should contain required average value in X/Y format, where X is numerator and Y is denominator.


Sample Input:                Sample Output:
5                            7/3

Sample Input:                Sample Output:
3                            2/1

*/

#include <iostream>
using namespace std;

int a, t, sum;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return 0;
    }
    return gcd(b, a % b);
}

int main()
{
    cin >> a;
    for (int i = 2; i < a; i++)
    {
        t = a;
        while (t)
        {
            sum += t % i;
            t /= i;
        }
    }
    int x = sum, y = a - 2;
    int gc = gcd(x, y);
    x /= gc;
    y = / gc;
    cout << x << "/" << y << endl;
    return 0;
}