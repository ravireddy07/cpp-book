#include <iostream>

int main(){

    const long long MOD = 1000000007;
    int t; std::cin>> t;
    while(t--){
        std::string s; std::cin >> s;
        long long x(1);
        for(long p = 0; p < s.size(); p++){
            if((p % 2 == 0) && (s[p] == 'l')){x = 2 * x;}
            if((p % 2 == 0) && (s[p] == 'r')){x = 2 * x + 2;}
            if((p % 2 == 1) && (s[p] == 'l')){x = 2 * x - 1;}
            if((p % 2 == 1) && (s[p] == 'r')){x = 2 * x + 1;}
            x %= MOD;
        }

        std::cout << x << std::endl;
    }

    return 0;
}
