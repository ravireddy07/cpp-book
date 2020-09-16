#include <cstdio>
#include <map>

long find(long n, std::map<long, long> &memo){

    if(n < 12){return n;}
    if(memo.count(n) > 0){return memo[n];}

    long cand = find(n/2, memo) + find(n / 3, memo) + find(n / 4, memo);
    long ans = (cand > n) ? cand : n;
    memo[n] = ans;
    return ans;
}



int main(){

    long n; 
    std::map<long, long> computed;
    while(scanf("%ld\n", &n) == 1){printf("%ld\n", find(n, computed));}

    return 0;
}
