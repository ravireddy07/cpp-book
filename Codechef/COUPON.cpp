#include <cstdio>
#include <vector>

int main(){

    int t; scanf("%d", &t);
    while(t--){
        long n, m; scanf("%ld %ld", &n, &m);
        std::vector<std::vector<long long> > a(n, std::vector<long long>(m, 0));
        std::vector<std::vector<long long> > b(n, std::vector<long long>(m, 0));
        std::vector<std::vector<long long> > dp(n, std::vector<long long>(m, 0));

        for(long p = 0; p < n; p++){for(long q = 0; q < m; q++){scanf("%lld", &a[p][q]);}}
        for(long p = 0; p < n; p++){for(long q = 0; q < m; q++){scanf("%lld", &b[p][q]);}}
        for(long q = 0; q < m; q++){dp[0][q] = a[0][q];}

        for(long p = 1; p < n; p++){
            for(long q = 0; q < m; q++){
                long long best(-1);
                for(long r = 0; r < m; r++){
                    long long cand = dp[p - 1][r] + a[p][q] - (q == r) * b[p - 1][q];
                    if((best < 0) || (cand < best)){best = cand;}
                }
                dp[p][q] = best;
            }
        }

        long long ans(dp[n - 1][0]);
        for(int q = 0; q < m; q++){ans = (ans < dp[n - 1][q]) ? ans : dp[n - 1][q];}
        printf("%lld\n", ans);
    }

    return 0;
}
