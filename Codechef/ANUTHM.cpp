#include <cstdio>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        double n, m; scanf("%lf %lf\n", &n, &m);
        printf("%.7lf\n", m + n - 1);  //The sum of each diagonal is equal to 1 :-)
    }

    return 0;
}
