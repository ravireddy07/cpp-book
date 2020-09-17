#include<cstdio>
#include<vector>
#include<map>

int main(){

    int t; scanf("%d\n", &t);
    while(t--){
        long n; scanf("%ld\n", &n);
        std::map<long, std::vector<long> > left;
        for(long p = 0; p < n; p++){
            long a; scanf("%ld", &a);
            if(left.count(a) <= 0){std::vector<long> temp; left[a] = temp;}
            left[a].push_back(p);
        }

        std::vector<long> order(n);
        long index(n);
        for(long p = 0; p < n; p++){
            if(left.count(p) <= 0){continue;}
            std::vector<long> v = left[p];
            for(long q = v.size() - 1; q >= 0; q--){
                long pos = v[q];
                order[pos] = index--;
            }
        }

        for(long p = 0; p < n; p++){printf("%ld ", order[p]);}
        puts("");
    }

    return 0;
}
