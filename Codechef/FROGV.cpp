#include <cstdio>
#include <vector>
#include <algorithm>

int main(){

    long n, k, p; scanf("%ld %ld %ld\n", &n, &k, &p);
    std::vector<std::pair<long, long> > x(n);
    for(int r = 0; r < n; r++){
        long d; scanf("%ld", &d);
        x[r] = std::make_pair(d, r + 1);
    }
    sort(x.begin(), x.end());
    std::vector<long> g(n + 1);
    g[0] = x[0].second;
    for(int r = 0; r < n; r++){g[r] = (x[r - 1].first + k < x[r].first) ? x[r].second : g[r - 1];}
    while(p--){
        long a, b; scanf("%ld %ld\n", &a, &b);
        puts( (g[a] == g[b]) ? "Yes" : "No");
    }

    return 0;
}
