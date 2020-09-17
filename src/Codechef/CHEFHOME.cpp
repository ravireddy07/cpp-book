#include <cstdio>
#include <vector>
#include <algorithm>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        int n; scanf("%d\n", &n);
        std::vector<long> x(n);
        std::vector<long> y(n);
        for(int p = 0; p < n; p++){scanf("%ld %ld\n", &x[p], &y[p]);}

        if(n % 2){puts("1"); continue;}

        long long num(1);
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        num *= (1 + x[n/2] - x[(n - 1) / 2]);
        num *= (1 + y[n/2] - y[(n - 1) / 2]);
        printf("%lld\n", num);
    }

    return 0;
}
