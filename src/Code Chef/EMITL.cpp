#include <iostream>
#include <vector>

int main(){

    std::ios_base::sync_with_stdio(false);
    const int N = 26;

    int t; std::cin >> t;
    while(t--){
        std::string s; std::cin >> s;
        long e(0), m(0), i(0), t(0), l(0);
        for(size_t p = 0; p < s.size(); p++){
            if(s[p] == 'E'){++e;}
            if(s[p] == 'M'){++m;}
            if(s[p] == 'I'){++i;}
            if(s[p] == 'T'){++t;}
            if(s[p] == 'L'){++l;}
        }

        if(s.size() == 9 && e == 1 && m == 2 && i == 2 && t == 2 && l == 2){std::cout << "YES" << std::endl;}
        else if(e >= 2 && m >= 2 && i >= 2 && t >= 2 && l >= 2){std::cout << "YES" << std::endl;}
        else{std::cout << "NO" << std::endl;}
    }

    return 0;
}
