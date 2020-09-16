#include <cstdio>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        double t1, t2, t3, t4; scanf("%lf %lf %lf %lf\n", &t1, &t2, &t3, &t4);
        printf("%.7lf\n", t1 / (t1 + t2));
    }

    return 0;
}
