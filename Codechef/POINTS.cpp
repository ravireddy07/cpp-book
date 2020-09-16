#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

bool gridSort(std::pair<long, long> a, std::pair<long, long> b){
    if(a.first < b.first){return true;}
    else if(a.first > b.first){return false;}
    else if(a.first == b.first){return (b.second < a.second);}
    return 0;
}


int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        std::vector<std::pair<long, long> > v(n);
        for(long p = 0; p < n; p++){
            long x, y; scanf("%ld %ld\n", &x, &y);
            v[p] = std::make_pair(x, y);
        }

        sort(v.begin(), v.end(), gridSort);

        double dist(0);
        for(long p = 1; p < n; p++){
            long dx = v[p].first - v[p - 1].first;
            long dy = v[p].second - v[p - 1].second;
            dist += sqrt(dx * dx + dy * dy);
        }

        printf("%.2lf\n", dist);
    }

    return 0;
}
