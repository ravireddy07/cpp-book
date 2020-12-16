#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    std::ios_base::sync_with_stdio(false);
    long t; std::cin >> t;
    while(t--){
        int n; std::cin >> n;
        std::vector<int64_t> a(n);
        for(int p = 0; p < n; p++){std::cin >> a[p];}
        std::vector<int64_t> low(n, 0);
        std::vector<int64_t> high(n, 0);

        low[0] = high[0] = a[0];
        for(int p = 1; p < n; p++){
            std::vector<int64_t> cand(6);
            cand[0] = low[p - 1] + a[p];
            cand[1] = low[p - 1] - a[p];
            cand[2] = low[p - 1] * a[p];
            cand[3] = high[p - 1] + a[p];
            cand[4] = high[p - 1] - a[p];
            cand[5] = high[p - 1] * a[p];
            sort(cand.begin(), cand.end());
            low[p] = cand[0]; high[p] = cand.back();
        }

        std::cout << low.back() << std::endl;
    }

    return 0;
}
