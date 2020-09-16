#include <cstdio>
#include <vector>
#include <algorithm>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long n, m; scanf("%ld %ld\n", &n, &m);

        std::vector<long> s(m);
        for(long p = 0; p < m; p++){scanf("%ld", &s[p]);}

        std::vector<std::vector<long> > v(n);
        for(long p = 0; p < n; p++){
            long c; scanf("%ld", &c);
            while(c--){long g; scanf("%ld", &g); v[p].push_back(g);}
            sort(v[p].begin(), v[p].end());
        }

        long long total(0);
        for(long p = 0; p < m; p++){
            long r = s[p];
            if(v[r].size() <= 0){continue;}
            total += v[r].back(); v[r].pop_back();
        }

        printf("%lld\n", total);
    }

    return 0;
}
