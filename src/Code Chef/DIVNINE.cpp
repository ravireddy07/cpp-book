#include <iostream>

int main(){

    std::ios_base::sync_with_stdio(false);
    long t; scanf("%ld\n", &t);
    while(t--){
        std::string s; std::cin >> s;
        long sum(0), inc(0), dec(0);
        for(long p = 0; p < s.size(); p++){
            sum += (s[p] - '0');
            dec += (s[p] - '0');
            inc += ('9' - s[p]);
        }

        long mod = sum % 9;
        if(mod <= 4 && dec >= mod){printf("%ld\n", mod);}
        else if(mod >= 5 && inc >= 9 - mod){printf("%ld\n", 9 - mod);}
        else if(mod <= 4 && inc >= 9 - mod){printf("%ld\n", 9 - mod);}
        else if(mod >= 5 && dec >= mod){printf("%ld\n", mod);}
        else{puts("-1");}
    }

    return 0;
}
