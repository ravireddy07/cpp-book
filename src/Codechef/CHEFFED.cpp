#include <cstdio>

int sumDigits(long x){
    int sum(0);
    while(x > 0){sum += x % 10; x /= 10;}
    return sum;
}


int main(){

    long n; scanf("%ld\n", &n);
    long count(0);
    for(long p = n - 200; p <= n; p++){
        if(p <= 0){continue;}
        count += (p + sumDigits(p) + sumDigits(sumDigits(p)) == n);
    }

    printf("%ld\n", count);

    return 0;
}
