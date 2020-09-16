#include <iostream>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        std::string s; std::cin >> s;
        long a(0), b(0);
        for(size_t p = 0; p < s.size(); p++){
            if(p % 2){
                a += (s[p] == '+');
                b += (s[p] == '-');
            }
            else{
                a += (s[p] == '-');
                b += (s[p] == '+');
            }
        }

        std::cout << ((a < b) ? a : b) << std::endl;
    }

    return 0;
}
