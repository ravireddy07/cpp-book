#include <cstdio>
#include <vector>

int main(){

    long t; scanf("%ld\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        std::vector<long long> a(n);
        long long sum(0);
        for(long p = 0; p < n; p++){
            scanf("%lld", &a[p]);
            sum += a[p];
        }

        long long A = sum / (n - 1);

        for(long p = 0; p < n; p++){printf("%lld ", A - a[p]);}
        puts("");
    }

    return 0;
}
