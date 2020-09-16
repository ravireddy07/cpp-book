#include <iostream>
#include <set>

int main(){

    std::ios_base::sync_with_stdio(false);
    int t; std::cin >> t;
    while(t--){
        std::string s; std::cin >> s;
        std::set<std::string> codes;
        for(int p = 0; p < s.size() - 1; p++){codes.insert(s.substr(p, 2));}
        std::cout << codes.size() << std::endl;
    }

    return 0;
}
