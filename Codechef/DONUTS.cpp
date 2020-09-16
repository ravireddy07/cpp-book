#include <cstdio>

int main(){

    long t; scanf("%ld\n", &t);
    while(t--){
        long n, m; scanf("%ld %ld\n", &n, &m);
        long a(0);
        for(int p = 0; p < m; p++){long x; scanf("%ld", &x); a += (x == 1);}
        long ans = m - a - 1;
        if(ans < m / 2){ans = m / 2;}
        printf("%ld\n", ans);
    }

    return 0;
}
