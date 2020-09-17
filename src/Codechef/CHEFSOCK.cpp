#include <cstdio>

int main(){

    long j, s, m; scanf("%ld %ld %ld\n", &j, &s, &m);
    puts( (((m - j) / s) % 2) ? "Unlucky Chef" : "Lucky Chef");

    return 0;
}
