#include<bits/stdc++.h>
using namespace std;
long long int inf = 2*1e18;


bool is_safe_mul(long long int a, long long int &b) {
    return(a<=(inf+b-1)/b);
}

void generate(vector<long long int> &ans, vector<long long int> &v, int L, int R, long long int K, long long int prod) {
    if(L == R) {
        return;
    }
    if(is_safe_mul(prod, v[L])) {
        prod *= v[L];
        generate(ans, v, L + 1, R, K, prod);
        if (prod<=K) {
            ans.push_back(prod);
        }
        prod /= v[L];

    }
    generate(ans, v, L + 1, R, K, prod);
}

unsigned long long int noSubProdLessK(vector<long long int> &v, int n, long long int k) {
    vector<long long int>left;
    vector<long long int>right;
    generate(left, v, 0, n / 2, k, 1);
    generate(right, v, n / 2, n, k, 1);
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());


    unsigned long long int ans = left.size()+right.size();

    for(long long i : left) {
        auto pos = upper_bound(right.begin(), right.end(), k/i)-right.begin();
        ans+=pos;
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    long long int k;
    cin>>k;
    vector<long long int>v(n);
    for(auto &it: v) {
    	cin>>it;
	}
    cout<<noSubProdLessK(v, n, k);
    return 0;
}
