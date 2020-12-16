#include <cstdio>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long long n, s; scanf("%lld %lld\n", &n, &s);
        long long S = n * (n + 1) / 2;
        long long diff = S - s;

        long count(0);
        while(diff > 0){++count; diff -= count;}
        printf("%ld\n", count);
    }

    return 0;
}
