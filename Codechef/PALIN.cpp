#include<iostream>

std::string nextPalindrome(std::string s){

    size_t n = s.size();
    bool allNines(true);
    for(size_t p = 0; p < s.size(); p++){if(s[p] != '9'){allNines = false; break;}}
    if(allNines){
        for(size_t p = 0; p < s.size(); p++){s[p] = '0';}
        s = "1" + s; s.back() = '1';
        return s;
    }

    int state(0);
    for(size_t p = 0; p < n; p++){
        if(s[p] > s[n - 1 - p]){state = 1;}
        else if(s[p] < s[n - 1 - p]){state = -1;}
        s[n - 1 - p] = s[p];
    }

    if(state <= 0){
        size_t index = (n - 1) / 2;
        while(s[index] == '9'){s[index] = s[n - 1 - index] = '0'; ++index;}
        ++s[index]; s[n - 1 - index] = s[index];
    }

    return s;
}


int main(){

    std::ios_base::sync_with_stdio(false);
    long t; std::cin >> t;
    while(t--){
        std::string s; std::cin >> s;
        std::cout << nextPalindrome(s) << std::endl;
    }

    return 0;
}
