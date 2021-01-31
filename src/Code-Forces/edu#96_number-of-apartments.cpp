// https://codeforces.com/contest/1430/problem/A

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void test() {
    ll n, a=0,b=0,c=0;
    cin >> n;
    if(n < 5 && n != 3){
        cout << -1 << endl;
        return;
    }

    while(n > 0) {        
        if(n%3 == 0) {
            a += (n / 3);
            cout << a << " " << b << " " << c << endl;
            return;
        }
        else if(n%5 == 0) {
            b += (n / 5);
            cout << a << " " << b << " " << c << endl;
            return;
        }
        else if(n%7 == 0) {
            c += (n / 7);
            cout << a << " " << b << " " << c << endl;
            return;
        }
        else if(n >= 7 && n > 14) {
            n -= 7;
            c++;
        }
        else if(n >= 5 && n >= 10) {
            n -= 5;
            b++;
        }
        else if(n >= 3) {
            n -= 3;
            a++;
        }
        else {
            cout << -1 << endl;
            return;
        }
    }
    cout << a << " " << b << " " << c << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        test();
    }
    return 0;
}