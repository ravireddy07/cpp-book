#include <cstdio>
#include <vector>

long long gcd(long long a, long long b){return (a == 0) ? b : gcd(b % a, a);}

int main(){

    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        std::vector<long long> a(n, 0);
        for(int p = 0; p < n; p++){scanf("%lld\n", &a[p]);}

        long long ans(0);
        for(int p = 0; p < n; p++){
            if(ans > 0){break;}
            for(long long s = 2; s * s <= a[p]; s++){if(a[p] % (s * s) == 0){ans = s; break;}}
        }

        for(int p = 0; p < n; p++){
            if(ans > 0){break;}
            for(int q = p + 1; q < n; q++){
                long long g = gcd(a[p], a[q]);
                if(g > 1){ans = g; break;}
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}
