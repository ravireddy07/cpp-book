#include <iostream>
#include <vector>

int main(){

    std::ios_base::sync_with_stdio(false);

    long n, m; std::cin >> n >> m;
    std::vector<long> a(n);
    for(long p = 0; p < n; p++){std::cin >> a[p];}
    long offset(0);
    while(m--){
        std::string s; long x; std::cin >> s >> x;
        if(s[0] == 'C'){offset += x;}
        if(s[0] == 'A'){offset -= x;}
        offset %= n; offset = (offset + n) % n;  //ensure that it is positive;
        if(s[0] == 'R'){printf("%ld\n", a[(x + offset - 1 + 2 * n) % n]);}
    }

    return 0;
}
