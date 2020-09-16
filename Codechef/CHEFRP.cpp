#include <cstdio>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        long total(0), min(1000000);
        while(n--){
            long a; scanf("%ld\n", &a);
            total += a;
            min = (a < min) ? a : min;
        }

        if(min < 2){puts("-1");}
        else{printf("%ld\n", total - min + 2);}
    }

    return 0;
}
