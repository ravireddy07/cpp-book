#include <cstdio>
#include <vector>
#include <algorithm>

int main(){

    long n, d; scanf("%ld %ld\n", &n, &d);
    std::vector<long> a(n);
    for(long p = 0; p < n; p++){scanf("%ld", &a[p]);}
    sort(a.begin(), a.end());

    long count(0);
    long ind(1);
    while(ind < n){
        if(a[ind] - a[ind - 1] <= d){++count; ++ind;}
        ++ind;
    }

    printf("%ld\n", count);

    return 0;
}
