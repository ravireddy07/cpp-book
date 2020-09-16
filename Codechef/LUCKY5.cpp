#include <iostream>

int main(){

    std::ios_base::sync_with_stdio(false);
    int t; std::cin >> t;
    while(t--){
        std::string s; std::cin >> s;
        int count(0);
        for(size_t p = 0; p < s.size(); p++){count += ((s[p] != '4') && (s[p] != '7'));}
        std::cout << count << std::endl;
    }

    return 0;
}
