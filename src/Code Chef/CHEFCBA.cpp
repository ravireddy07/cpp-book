#include <cstdio>

int main(){

    long a, b, c, d; scanf("%ld %ld %ld %ld\n", &a, &b, &c, &d);
    puts((a * b == c * d) || (a * c == b * d) || (a * d == b * c) ? "Possible" : "Impossible");

    return 0;
}
