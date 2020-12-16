#include <iostream>

uint64_t gcd(uint64_t a, uint64_t b){return (a == 0) ? b : gcd(b % a, a);}

uint64_t nCr(uint64_t n, uint64_t k){
    
    uint64_t num(1), den(1);
    for(int p = 1; p <= k; p++){
        num *= (n - k + p); den *= p;
        uint64_t div = gcd(num, den);
        num /= div; den /= div;
    }

    return (num / den);  //den should be trivially one;
}


int main(){

    std::ios_base::sync_with_stdio(false);
    int t; std::cin >> t;
    while(t--){
        long n, r; std::cin >> n >> r;
        std::cout << nCr(n - 1, r - 1) << std::endl;
    }

    return 0;
}
