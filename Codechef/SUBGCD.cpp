#include <cstdio>

long gcd(long a, long b){return (a == 0) ? b : gcd(b % a, a);}

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        long current(0);
        for(long p = 0; p < n; p++){
            long a; scanf("%ld", &a); current = gcd(current , a);
        }
        printf("%ld\n", (current == 1) ? n : -1);
    }

    return 0;
}
