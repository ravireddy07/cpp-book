#include <cstdio>
#include <vector>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        int n, k; scanf("%d %d\n", &n, &k);
        std::vector<int> mods(k + 1, 0);
        for(int p = 0; p < n; p++){
            int a; scanf("%d", &a);
            ++mods[a % (k + 1)];
        }
        
        bool possible(false);
        for(int p = 0; p <= k; p++){if(mods[p] >= n - 1){possible = true; break;}}
        puts(possible ? "YES" : "NO");
    }

    return 0;
}
