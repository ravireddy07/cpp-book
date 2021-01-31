#include <cstdio>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long long L, D, S, C; scanf("%lld %lld %lld %lld\n", &L, &D, &S, &C);
        long long likes(S);
        bool alive = (S >= L);
        for(int p = 2; p <= D; p++){
            likes *= (1 + C);
            if(likes >= L){alive = 1; break;}
        }
        puts(alive ? "ALIVE AND KICKING" : "DEAD AND ROTTING");
    }

    return 0;
}
