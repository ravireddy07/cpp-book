// https://codeforces.com/contest/1430/problem/C

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void test() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n;i++) {
        v[i] = i + 1;
    }
    // 1 2 3 4
    ll res = v[n-1];
    v.erase(v.begin() + n - 1);
    vector<ll> r;
    for (int i = n-2; i >= 0; i--) {
        r.push_back(res);
        r.push_back(v[i]);
        if((res + v[i]) % 2 != 0) {
            res = (res + v[i]+1) / 2;
        }
        else {
            res = (res + v[i]) / 2;
        }
        v.erase(v.begin() + i);
    }
 
    cout << res << endl;
    for (int i = 0; i < r.size(); i+=2) {
        cout << r[i] << " " << r[i + 1] << endl;
    }
    return;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        test();
    }
    return 0;
}