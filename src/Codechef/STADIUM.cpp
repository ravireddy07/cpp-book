#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

bool compEnd(std::pair<int, int> a, std::pair<int, int> b){

    if(a.second < b.second){return true;}
    else if(a.second == b.second){return a.first <= b.first;}
    else{return false;}
}


int main(){

    long n; scanf("%ld\n", &n);
    std::vector<std::pair<int, int> > a(n);
    for(long p = 0; p < n; p++){
        long x, y; scanf("%ld %ld\n", &x, &y);
        a[p] = std::make_pair(x, x + y);
    }

    sort(a.begin(), a.end(), compEnd);

    long count(0), taken(-1);
    for(long p = 0; p < a.size(); p++){if(taken < a[p].first){++count; taken = a[p].second;}}
    printf("%ld\n", count);

    return 0;
}
