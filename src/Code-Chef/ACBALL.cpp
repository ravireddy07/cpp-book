#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x, y;
        cin >> x >> y;
        string z(x);
        cout << z << endl;
        for (int p = 0; p < z.size(); p++)
        {
            if (x[p] == 'B' && y[p] == 'B')
                z[p] = 'W';
            else if (x[p] == 'W' && y[p] == 'W')
                z[p] = 'B';
            else
                z[p] = 'B';
        }
        cout << z << endl;
    }
    return 0;
}
