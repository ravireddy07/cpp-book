#include <cstdio>

int main(){

    const int S = 100;
    int t; scanf("%d\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        long total(0), zeroes(0);
        for(int p = 0; p < n; p++){
            int b; scanf("%d", &b);
            if(b == 0){++zeroes;}
            total += b;
        }

        bool possible = (total >= S) && (total < S + (n - zeroes));
        puts(possible ? "YES" : "NO");
    }

    return 0;
}
