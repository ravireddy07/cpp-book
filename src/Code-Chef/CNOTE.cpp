#include <cstdio>

int main(){

    long t; scanf("%ld\n", &t);
    while(t--){
        long x, y, k, n; scanf("%ld %ld %ld %ld\n", &x, &y, &k, &n);
        bool possible(0);
        while(n--){
            long a, b; scanf("%ld %ld\n", &a, &b);
            if((x - y <= a) && (b <= k)){possible = 1;}
        }

        puts(possible ? "LuckyChef" : "UnluckyChef");
    }

    return 0;
}
