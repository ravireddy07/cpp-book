#include <iostream>

int main(){

    std::ios_base::sync_with_stdio(false);
    long t; std::cin >> t;
    while(t--){
        long n; std::cin >> n;
        std::string s; std::cin >> s;
        long long ones(0);
        for(size_t p = 0; p < n; p++){ones += (s[p] == '1');}
        std::cout << (ones * (ones + 1) / 2) << std::endl;
    }

    return 0;
}
