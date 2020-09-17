#include <cstdio>
#include <vector>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        long v(0);
        for(long p = 0; p < n; p++){
            long w; scanf("%ld", &w);
            v = (v > (w + p)) ? v : (w + p);
        }
        printf("%ld\n", v);
    }

    return 0;
}
