#include <cstdio>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        puts((n % 6) ? "Chef" : "Misha");
    }

    return 0;
}
