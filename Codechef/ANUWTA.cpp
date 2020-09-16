#include <cstdio>

int main(){

    long t; scanf("%ld\n", &t);
    while(t--){
        long long n; scanf("%lld\n", &n);
        printf("%lld\n", n * (n + 3) / 2);
    }

    return 0;
}
