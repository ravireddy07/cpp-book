#include <cstdio>
#include <set>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        std::set<long> s;
        while(n--){long a; scanf("%ld", &a); s.insert(a);}
        printf("%ld\n", s.size());
    }

    return 0;
}
