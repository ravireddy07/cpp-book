#include <cstdio>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long r, g, b; scanf("%ld %ld %ld\n", &r, &g, &b);
        long k; scanf("%ld\n", &k);
        long long ans(1);
        ans += (r < (k - 1)) ? r : (k - 1);
        ans += (g < (k - 1)) ? g : (k - 1);
        ans += (b < (k - 1)) ? b : (k - 1);
        printf("%lld\n", ans);
    }

    return 0;
}
