#include <cstdio>
#include <vector>

bool isPerfectNumber(unsigned long long x){
    bool res(true);
    while(x > 0){
        long long d = x % 10;
        if((d != 0) && (d != 1) && (d != 4) && (d != 9)){res = false; break;}
        x /= 10;
    }
    return res;
}

std::vector<long long> getPerfectSquares(long long B){
    std::vector<long long> res;
    for(long long p = 1; p * p <= B; p++){if(isPerfectNumber(p * p)){res.push_back(p * p);}}
    return res;
}

int main(){

    std::vector<long long> psq = getPerfectSquares(10000000000ULL);

    int t; scanf("%d\n", &t);
    while(t--){
        long long a, b; scanf("%lld %lld\n", &a, &b);
        int count(0);
        for(int p = 0; p < psq.size(); p++){count += ((a <= psq[p]) && (psq[p] <= b));}
        printf("%d\n", count);
    }

    return 0;
}
