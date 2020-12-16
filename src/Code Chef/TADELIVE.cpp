#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

long absVal(long a){return (a >= 0) ? a : (-a);}

long compareAbsDiff(std::pair<long, long> a, std::pair<long, long> b){
    return (absVal(a.first - a.second) > absVal(b.first - b.second));
}


int main(){

    long n, x, y; scanf("%ld %ld %ld\n", &n, &x, &y);
    std::vector<std::pair<long, long> > tips(n);
    for(long p = 0; p < n; p++){scanf("%ld", &tips[p].first);}
    for(long p = 0; p < n; p++){scanf("%ld", &tips[p].second);}
    sort(tips.begin(), tips.end(), compareAbsDiff);
    long long total(0);
    for(long p = 0; p < n; p++){
        long u = tips[p].first;
        long v = tips[p].second;

        if((u >= v) && (x > 0)){total += u; --x;}
        else if((u < v) && (y > 0)){total += v; --y;}
        else if(x > 0){total += u; --x;}
        else if(y > 0){total += v; --y;}
    }

    printf("%lld\n", total);

    return 0;
}
