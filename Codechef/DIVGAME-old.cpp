#include <cstdio>
#include <vector>

int main(){

    long n = 100000001;
    std::vector<bool> res(n + 1, 0);
    res[0] = 0; res[1] = 0; res[2] = 1;
    for(long p = 3; p <= n; p++){
        if(res[p]){continue;}
        else if(!res[p - 1]){res[p] = 1;}
        else{for(long q = 2 * p; q <= n; q += p){res[q] = 1;}}
    }

    long t; scanf("%ld\n", &t);
    while(t--){
        long x; scanf("%ld\n", &x);
        puts(res[x] ? "Mike" : "Tom");
    }

    return 0;
}
