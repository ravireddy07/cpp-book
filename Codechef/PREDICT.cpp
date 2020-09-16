#include <cstdio>

int main(){

    const long M = 10000;
    long t; scanf("%ld\n", &t);
    while(t--){
        double p; scanf("%lf\n", &p);
        if(p < 0.5){p = 1 - p;}
        printf("%.7lf\n", p * (3 - 2 * p) * M);
    }

    return 0;
}
