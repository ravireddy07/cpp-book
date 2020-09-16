#include <cstdio>
#include <vector>

bool checkPrime(long long x){
    std::vector<long long> firstPrimes{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

    if(x <= 1 || x % 2 == 0){return false;}
    for(int p = 0; p < firstPrimes.size(); p++){
        if(x == firstPrimes[p]){return true;}
        if(x % firstPrimes[p] == 0){return false;}
    }

    for(long long p = 9; p * p <= x; p += 2){if(x % p == 0){return false;}}
    return true;
}


int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long long m, n; scanf("%lld %lld\n", &m, &n);
        for(long long p = m; p <= n; p++){if(checkPrime(p)){printf("%lld\n", p);}}
        puts("");
    }

    return 0;
}
