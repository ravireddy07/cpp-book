#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<long> getPath(long x){
    std::vector<long> path;
    while(x > 0){path.push_back(x); x /= 2;}
    std::reverse(path.begin(), path.end());
    return path;
}

int main(){

    long n; scanf("%ld\n", &n);
    while(n--){
        long x, y; scanf("%ld %ld\n", &x, &y);
        std::vector<long> a = getPath(x);
        std::vector<long> b = getPath(y);

        long steps = a.size() + b.size();
        for(int p = 0; p < a.size() && p < b.size(); p++){
            if(a[p] == b[p]){steps -= 2;}
            else{break;}
        }

        printf("%ld\n", steps);
    }

    return 0;
}
