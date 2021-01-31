#include <cstdio>
#include <vector>

std::vector<bool> getPrimes(long B){

    std::vector<bool> isPrime(B + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for(int p = 2; p * p <= B; p++){
        if(!isPrime[p]){continue;}
        for(int q = 2 * p; q <= B; q += p){isPrime[q] = 0;}
    }

    return isPrime;
}



int main(){

    const long B = 3100;
    std::vector<bool> isPrime = getPrimes(B);
    int t; scanf("%d\n", &t);
    while(t--){
        int x, y; scanf("%d %d\n", &x, &y);
        int ans(1);
        while(!isPrime[x + y + ans]){++ans;}
        printf("%d\n", ans);
    }

    return 0;
}
