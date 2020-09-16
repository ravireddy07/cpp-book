#include <cstdio>

int main(){

    long t; scanf("%ld\n", &t);
    while(t--){
        long long n1, n2, m; scanf("%lld %lld %lld\n", &n1, &n2, &m);
        long long rem = (n1 < n2) ? n1 : n2;
        rem = (rem < (m * (m + 1) / 2)) ? rem : (m * (m + 1) / 2);
        printf("%lld\n", n1 + n2 - 2 * rem);
    }

    return 0;
}
