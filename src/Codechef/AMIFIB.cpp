#include <iostream>
#include <vector>

int main(){

    const int N = 5000;
    std::vector<int64_t> fib(N, 0);
    fib[1] = 0; fib[2] = 1;
    for(int p = 3; p < N; p++){fib[p] = fib[p - 1] + fib[p - 2];} //OK to overflow

    int t; std::cin >> t;
    while(t--){
        std::string s; std::cin >> s;
        int64_t x(0);
        for(size_t p = 0; p < s.size(); p++){x = 10 * x + (s[p] - '0');} //OK to overflow

        bool found(0);
        for(int p = 1; p < N; p++){if(fib[p] == x){found = 1; break;}}
        std::cout << (found ? "YES" : "NO") << std::endl;
    }

    return 0;
}
