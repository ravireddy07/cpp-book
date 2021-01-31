#include <cstdio>

int main(){

    const int C = 360;
    long t; scanf("%ld\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        bool a1 = (C % n == 0);
        bool a2 = (n <= C);
        bool a3 = (n * (n + 1) / 2 <= C);
        printf("%c %c %c\n", (a1 ? 'y' : 'n'), (a2 ? 'y' : 'n'), (a3 ? 'y' : 'n'));
    }

    return 0;
}
