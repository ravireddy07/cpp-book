#include <cstdio>
#include <vector>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        int n; scanf("%d\n", &n);
        std::vector<std::vector<long> > a(n, std::vector<long>(n, 0));
        for(int row = 0; row < n; row++){for(int col = 0; col < n; col++){scanf("%ld", &a[row][col]);}}

        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(row > 0 && col > 0){a[row][col] += ((a[row - 1][col] > a[row][col - 1]) ? a[row - 1][col] : a[row][col - 1]);}
                else if(row > 0){a[row][col] += a[row - 1][col];}
                else if(col > 0){a[row][col] += a[row][col - 1];}
            }
        }

        double ans = a[n - 1][n - 1] / (2.0 * n - 3.0);
        if(ans < 0){puts("Bad Judges");} 
        else{printf("%.7lf\n", ans);}
    }
    
    return 0;
}
