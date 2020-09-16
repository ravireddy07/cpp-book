#include <cstdio>
#include <vector>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        std::vector<long> a(n);
        std::vector<long> b(n);
        for(int p = 0; p < n; p++){scanf("%ld", &a[p]);}
        for(int p = 1; p < n; p++){if(a[p] != a[p - 1]){b[p] = b[p - 1] = 1;}}
        long count(0);
        for(int p = 0; p < n; p++){count += b[p];}
        printf("%ld\n", count);
    }

    return 0;
}
