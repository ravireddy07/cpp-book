#include <iostream>

int main(){

    std::ios_base::sync_with_stdio(false);
    int t; scanf("%d\n", &t);
    while(t--){
        long n; std::cin >> n;
        std::string s("");
        std::string r("abc");
        for(long p = 0; p < n; p++){s += r[p % 3];}
        std::cout << s << std::endl;
    }

    return 0;
}
