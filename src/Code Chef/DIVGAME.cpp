#include <cstdio>
#include <vector>

bool game(long n){
    if(n == 2){return true;}
    if(n == 16){return false;}
    if(n == 17){return true;}
    if(n == 34){return false;}
    if(n == 289){return false;}
    for(long p = 2; p * p <= n; p++){if(n % p == 0){return true;}}
    return false;
}


int main(){

    long t; scanf("%ld\n", &t);
    while(t--){
        long x; scanf("%ld\n", &x);
        puts(game(x) ? "Mike" : "Tom");
    }

    return 0;
}
