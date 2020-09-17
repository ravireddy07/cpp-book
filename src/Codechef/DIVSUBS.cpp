#include <cstdio>
#include <vector>
#include <set>

int main(){

    long t; scanf("%ld", &t);
    while(t--){
        long n; scanf("%ld", &n);
        std::vector<long> a(n + 1);
        for(long p = 1; p <= n; p++){scanf("%ld", &a[p]);}

        long x(0), y(0);
        long long cumsum(0);
        std::vector<long> mods(n, -1); mods[0] = 0;
        for(long p = 1; p <= n; p++){
            cumsum += a[p]; cumsum %= n;
            if(mods[cumsum] >= 0){x = mods[cumsum] + 1; y = p; break;}
            mods[cumsum] = p;
        }

        printf("%ld\n", y - x + 1);
        for(long p = x; p <= y; p++){printf("%ld ", p);}
        puts("");
    }

    return 0;
}
