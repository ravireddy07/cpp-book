#include <cstdio>
#include <vector>

int main(){

    long t; scanf("%ld\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        std::vector<long> a(n, 0);
        for(long p = 0; p < n; p++){scanf("%ld", &a[p]);}
        bool possible(0);
        for(int p = 2; p < n; p++){if(a[p] == a[p - 1] && a[p] == a[p - 2]){possible = 1; break;}}
        puts(possible ? "Yes" : "No");
    }

    return 0;
}
