#include <cstdio>
#include <vector>

int main(){

    const int MOD = 100;
    int n; 
    while(scanf("%d\n", &n) == 1){
        std::vector<int> a(n);
        for(int p = 0; p < n; p++){scanf("%d", &a[p]);}

        std::vector<std::vector<long long> > smoke(n, std::vector<long long>(n, -1));
        std::vector<std::vector<long long> > color(n, std::vector<long long>(n, 0));
        for(int p = 0; p < n; p++){smoke[p][p] = 0; color[p][p] = a[p];}

        for(int len = 2; len <= n; len++){
            for(int row = 0; row <= n - len; row++){
                int col = row + len - 1;
                for(int p = 0; p < len - 1; p++){
                    long long cand = smoke[row][row + p] + smoke[row + 1 + p][col] + color[row][row + p] * color[row + 1 + p][col];
                    if((smoke[row][col] < 0) || (cand < smoke[row][col])){
                        smoke[row][col] = cand;
                        color[row][col] = (color[row][row + p] + color[row + 1 + p][col]) % MOD;
                    }
                }
            }
        }

        printf("%lld\n", smoke[0][n - 1]);
    }

    return 0;
}
