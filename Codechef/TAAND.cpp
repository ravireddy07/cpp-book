#include <cstdio>
#include <vector>
#include <algorithm>

int main(){

    long n; scanf("%ld\n", &n);
    std::vector<long> a(n);
    for(long p = 0; p < n; p++){scanf("%ld", &a[p]);}
    sort(a.begin(), a.end());

    long ans(0);
    for(int p = 1; p < n; p++){ans = (ans > (a[p - 1] & a[p])) ? ans : (a[p - 1] & a[p]);}
    printf("%ld\n", ans);

    return 0;
}
