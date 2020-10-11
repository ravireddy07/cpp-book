#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void test() {
    int n, k;
    ll f = 0;
    cin >> n >> k;
    vector<ll> v(n);
    for(int i = 0; i<n; i++) {
        cin >> v[i];
        f += v[i];
    }

    sort(v.begin(), v.end());
    if(f == 0) {
        cout << 0 << endl;
        return;
    }

    if(k >= n-1) {
        cout << f << endl;
        return;
    }
    
    if(k == 0) {
        cout << v[n-1]<<endl;
        return ;
    }

    ll res = 0;
    for (int i = v.size() - 2; i >= 0; i--)
    {
        if(k>0) {
            res += v[i];
            k--;
        }
        else
            break;
    }
    cout << res+v[n - 1] << endl;
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