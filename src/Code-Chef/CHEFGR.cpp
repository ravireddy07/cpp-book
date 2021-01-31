#include <cstdio>
#include <vector>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long n, m; scanf("%ld %ld\n", &n, &m);
        std::vector<long> a(n);
        long max(0);
        for(long p = 0; p < n; p++){
            scanf("%ld", &a[p]);
            max = (a[p] > max) ? a[p] : max;
        }

        long needed(0);
        for(long p = 0; p < n; p++){needed += (max - a[p]);}
        puts((needed == m) || ((needed - m) % n == 0) ? "Yes" : "No");
    }

    return 0;
}
