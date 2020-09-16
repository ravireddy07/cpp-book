#include <cstdio>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        int n, m, k; scanf("%d %d %d\n", &n, &m, &k);
        int ans(0);
        if((n==1 && m==1)|| (n==1 && m==2) || (n==2 && m==1)){ans=0;}
        else if(n==1 || m==1){ans=k;}
        else{ans=(k+1)/2;}
        printf("%d\n",ans);
    }

    return 0;
}
