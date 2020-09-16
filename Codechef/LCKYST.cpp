#include <cstdio>

int main(){

    long n; scanf("%ld\n", &n);
    while(n--){
        long long a; scanf("%lld\n", &a);
        int fives(0), twos(0);
        long long b(a);
        while(b % 2 == 0){++twos; b /= 2;}
        while(b % 5 == 0){++fives; b /= 5;}
        int diff = fives - twos;

        for(int p = 0; p < (diff + 1) / 2; p++){a *= 4;}
        printf("%lld\n", a);

    }

    return 0;
}
