#include <cstdio>
#include <set>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        std::set<long> s;
        while(n--){long x; scanf("%ld", &x); s.insert(x);}
        printf("%ld\n", s.size());
    }

    return 0;
}
