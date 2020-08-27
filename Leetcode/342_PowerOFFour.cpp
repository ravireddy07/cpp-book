// https://leetcode.com/problems/power-of-four/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0) return false;
        while(n%4==0){
            n>>=2;
        }
        if(n==1) return true;
        return false;
    }
};

int main()
{
    Solution a;
    int input = 16;
    cout << a.isPowerOfFour(input) << endl;
    return 0;
}