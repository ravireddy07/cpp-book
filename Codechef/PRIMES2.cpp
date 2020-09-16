#include <cstdio>
#include <vector>

std::vector<bool> getPrimes(long n){

    std::vector<bool> isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for(long p = 2; p * p <= n; p++){
        if(!isPrime[p]){continue;}
        for(long q = 2 * p; q <= n; q += p){isPrime[q] = 0;}
    }

    return isPrime;
}



int main(){

    const int N = 1000000;

    std::vector<bool> isPrime = getPrimes(N);
    std::vector<long long> primeList;
    for(long long p = 0; p < isPrime.size(); p++){if(isPrime[p]){primeList.push_back(p);}}

    while(true){
        long long x; scanf("%lld\n", &x);
        if(x == 0){break;}

        bool possible(0);
        long long u, v, w;
        for(long a = 0; a < primeList.size(); a++){
            if(possible){break;}
            long long cube = primeList[a] * primeList[a] * primeList[a];
            if(cube >= x){break;}
            for(long b = 0; b < primeList.size(); b++){
                long long square = primeList[b] * primeList[b];
                if(cube + square >= x){break;}
                long long c = x - cube - square;
                if(isPrime[c]){
                    possible = 1; 
                    u = c; v = primeList[b]; w = primeList[a];
                    break;
                }
            }
        }

        if(possible){printf("%lld %lld %lld\n", u, v, w);}
        else{puts("0 0 0");}

    }

    return 0;
}
