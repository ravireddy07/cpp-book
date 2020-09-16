#include <cstdio>
#include <vector>

int main(){

    const long long A = 26;
    const long long MOD = 1000000007;

    int t; scanf("%d\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        std::vector<bool> v(n, 0);
        long count(0);
        for(long p = 0; p < n; p++){
            if(v[p]){continue;}
            ++count;
            long current = p;
            while(!v[current]){
                v[current] = 1;
                current = 2 * current;
                if((current < n) || (n % 2 == 1)){++current;}
                current %= n;
            }
        }

        long long res(1);
        for(long p = 0; p < count; p++){res *= A; res %= MOD;}
        printf("%lld\n", res);

    }

    return 0;
}
