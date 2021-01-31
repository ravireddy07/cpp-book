#include <cstdio>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        bool possible(1);
        long r(n);
        while(r > 0){if(r % 2 == 0){possible = 0; break;}; r /= 2;}
        if(n == 1){n = 4;}  //Need positive integer
        printf("%ld\n", possible ? (n / 2) : (-1));
    }

    return 0;
}
