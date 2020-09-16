#include <cstdio>

int main(){
    
    int n; scanf("%d\n", &n);
    double min(1e8), max(-1);
    int mintr(0), maxtr(0);
    for(int p = 1; p <= n; p++){
        long x1, y1, x2, y2, x3, y3; scanf("%ld %ld %ld %ld %ld %ld\n", &x1, &y1, &x2, &y2, &x3, &y3);
        double area = 0.5 *((x1 - x3) * (y2 - y1) - (x1 - x2) * (y3 - y1)); //Shoelace formula
        if(area < 0){area = -area;}
        if(area <= min){min = area; mintr = p;}
        if(area >= max){max = area; maxtr = p;}
    }

    printf("%d %d\n", mintr, maxtr);

    return 0;
}
