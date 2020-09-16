#include <cstdio>
#include <vector>
#include <algorithm>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        int n, k; scanf("%d %d\n", &n, &k);
        std::vector<long> w(n);
        long long total(0);
        for(int p = 0; p < n; p++){scanf("%ld", &w[p]); total += w[p];}
        sort(w.begin(), w.end());
        long long small(0);
        for(int p = 0; p < k; p++){small += w[p];}
        printf("%lld\n", total - 2 * small);
    }

    return 0;
}
