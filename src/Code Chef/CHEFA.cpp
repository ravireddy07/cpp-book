#include <cstdio>
#include <vector>
#include <algorithm>

int main(){

    long t; scanf("%ld\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        std::vector<long> a(n);
        for(long p = 0; p < n; p++){scanf("%ld", &a[p]);}
        sort(a.begin(), a.end());
        long long total(0);
        for(int p = (n + 1) % 2; p < n; p += 2){total += a[p];}
        printf("%lld\n", total);
    }

    return 0;
}
