#include <cstdio>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long a, b; scanf("%ld %ld\n", &a, &b);
        puts( ((a % 2 == 0) || (b % 2 == 0)) ? "Tuzik" : "Vanka");  //Proof by induction
    }

    return 0;
}
