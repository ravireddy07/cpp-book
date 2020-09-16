#include <cstdio>
#include <iostream>
#include <vector>

int main(){

    long t; scanf("%ld\n", &t);
    while(t--){
        int n, m; scanf("%d %d\n", &n, &m);
        std::vector<std::pair<int, int> > a(m);
        for(int p = 0; p < m; p++){
            int x, y; scanf("%d %d\n", &x, &y);
            a[p] = std::make_pair(x, y);
        }

        if(m < 2){puts("YES");}
        else if(m > 2){puts("NO");}
        else{
            bool same = (a[0].first == a[1].first) ||(a[0].first == a[1].second) ||(a[0].second == a[1].first) ||(a[0].second == a[1].second);
            puts(same ? "YES" : "NO");
        }
    }

    return 0;
}
