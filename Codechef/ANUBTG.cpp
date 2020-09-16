#include <cstdio>
#include <vector>
#include <algorithm>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        std::vector<long> v(n);
        for(long p = 0; p < n; p++){scanf("%ld", &v[p]);}
        sort(v.begin(), v.end());
        long total(0);
        for(int p = 0; p < n; p++){total += ((n - 1 - p) % 4 <= 1) * v[p];}
        printf("%ld\n", total);
    }

    return 0;
}
