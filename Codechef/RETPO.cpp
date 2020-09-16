#include <cstdio>

int main(){

    long t; scanf("%ld\n", &t);
    while(t--){
        long x, y; scanf("%ld %ld\n", &x, &y);
        if(x < 0){x = -x;}
        if(y < 0){y = -y;}
        long res = 2 * ((x > y) ? x : y);
        res += ((x > y) ? 1 : (-1)) * ((x + y) % 2);
        printf("%ld\n", res);
    }

    return 0;
}
