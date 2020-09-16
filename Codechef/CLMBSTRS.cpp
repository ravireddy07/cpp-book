#include <cstdio>
#include <vector>

int countOnes(long long x){
    int count(0);
    while(x > 0){count += (x % 2); x /= 2;}
    return count;
}

int main(){

    const long N = 1000000;
    const long long MOD = 1000000007;
    std::vector<long long> f(N + 1);
    f[0] = 1; f[1] = 1;
    for(long p = 2; p <= N; p++){f[p] = (f[p - 1] + f[p - 2]) % MOD;}

    long t; scanf("%ld\n", &t);
    while(t--){
        long n, g; scanf("%ld %ld\n", &n, &g);
        puts((countOnes(n) == g) ? "CORRECT" : "INCORRECT");
    }

    return 0;
}
