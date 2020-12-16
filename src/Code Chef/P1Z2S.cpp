#include <cstdio>

int main(){

    long n; scanf("%ld\n", &n);
    long long count(0);
    for(long p = 0; p < n; p++){long a; scanf("%ld", &a); count += a;}
    printf("%lld\n", (n > (count + 1)/ 2) ? n : (count + 1) / 2);

    return 0;
}
