#include <cstdio>
#include <vector>
#include <algorithm>

int main(){
    
    long long n, x; scanf("%lld %lld\n", &n, &x);
    std::vector<long long> a(n, 0);
    for(long long p = 0; p < n; p++){scanf("%lld", &a[p]);}
    sort(a.begin(), a.end());

    long long failed(n);
    for(int p = 0; p < n; p++){
        long long needed = (a[p] + 1) / 2;
        if(x >= needed){a[p] -= needed; x -= needed; --failed;}
    }

    long long succeeded(0);
    for(int p = 0; p < n; p++){if(x >= a[p]){x -= a[p]; ++succeeded;}}

    printf("%lld %lld\n", failed, succeeded);

    return 0;
}
