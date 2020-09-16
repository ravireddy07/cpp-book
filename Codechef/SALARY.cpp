#include <cstdio>
#include <vector>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        int n; scanf("%d\n", &n);
        std::vector<long> a(n);
        long min = 10000001;
        for(int p = 0; p < n; p++){
            scanf("%ld", &a[p]);
            min = (a[p] < min) ? a[p] : min;
        }

        long count(0);
        for(int p = 0; p < n; p++){count += (a[p] - min);}
        printf("%ld\n", count);
    }

    return 0;
}
