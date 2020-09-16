#include <cstdio>
#include <vector>
#include <map>

std::vector<long> getPrimeList(long B){

    std::vector<bool> isPrime(B + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for(long p = 2; p * p <= B; p++){
        if(!isPrime[p]){continue;}
        for(long q = 2 * p; q <= B; q += p){isPrime[q] = 0;}
    }

    std::vector<long> primeList;
    for(long p = 0; p <= B; p++){if(isPrime[p]){primeList.push_back(p);}}
    return primeList;
}

std::vector<long> getPrimeFactors(long x, std::vector<long> primeList){

    std::vector<long> primeFactors;
    for(long p = 0; p < primeList.size(); p++){
        long cp = primeList[p];
        while(x % cp == 0){primeFactors.push_back(cp); x /= cp;}
    }
    return primeFactors;
}

int main(){

    const long B = 1000000;
    std::vector<long> primeList = getPrimeList(B);
    int t; scanf("%d\n", &t);
    while(t--){
        int n; scanf("%d", &n);
        std::map<long, long> primeCount;
        while(n--){
            long a; scanf("%ld\n", &a);
            std::vector<long> v = getPrimeFactors(a, primeList);
            for(int p = 0; p < v.size(); p++){
                long prime = v[p];
                if(primeCount.count(prime) <= 0){primeCount[prime] = 0;}
                ++primeCount[prime];
            }
        }

        long long total(1);
        for(std::map<long, long>::iterator mapIter = primeCount.begin(); mapIter != primeCount.end(); mapIter++){
            long u = mapIter->second;
            total *= (u + 1);
        }

        printf("%lld\n", total);
    }

    return 0;
}
