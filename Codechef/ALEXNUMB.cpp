#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << n * (n - 1) / 2 << endl;
    }
    return 0;
}
