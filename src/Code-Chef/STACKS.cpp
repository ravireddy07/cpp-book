#include <cstdio>
#include <vector>
#include <algorithm>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        std::vector<long> a;
        while(n--){
            long x; scanf("%ld", &x);
            if(a.empty() || a.back() <= x){a.push_back(x);}
            else{
                std::vector<long>::iterator vecIter = std::upper_bound(a.begin(), a.end(), x);
                *vecIter = x;
            }
        }

        printf("%ld ", a.size());
        for(long p = 0; p < a.size(); p++){printf("%ld ", a[p]);}
        puts("");
    }

    return 0;
}
