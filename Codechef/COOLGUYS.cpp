#include <iostream>
#include <cmath>

uint64_t gcd(uint64_t a, uint64_t b){return (a == 0) ? b : gcd(b % a, a);}

int main(){

    std::ios_base::sync_with_stdio(false);
    long t; std::cin >> t;
    while(t--){
        uint64_t n; std::cin >> n;
        uint64_t num(0), den(n * n);
        for(long p=1; p * p <= n; p++){num += n / p;}
        num *= 2; 
        long long sn = sqrt(n);
        num -= sn * sn;

        uint64_t div = gcd(num, den);
        num /= div; den /= div;
        std::cout << num << "/" << den << std::endl;
    }

    return 0;
}
