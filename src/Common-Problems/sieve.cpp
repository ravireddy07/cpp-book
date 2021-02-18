#include <bits/stdc++.h>
#define maxx 100005
using namespace std;

bool sieve[maxx] = {};
int main()
{
    sieve[0] = true;
    sieve[1] = true;
    for (int i = 2; i <= sqrt(maxx); i++)
        if (!sieve[i])
            for (int j = i; j * i < maxx; j++)
                sieve[j * i] = true;

    for (int i = 0; i < maxx; i++)
        if (!sieve[i])
            cout << i << " ";

    cout << "\n";
}