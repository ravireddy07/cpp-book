// https://leetcode.com/problems/open-the-lock/

#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<bool> seen;
public:
    int openLock(vector<string>& deadends, string target) {
        seen = vector<bool>(10000,false);
        for(auto x : deadends)
            seen[stoi(x)] = 1;
        queue<pair<string,int>> qu;
        if(!seen[stoi("0000")])qu.push({"0000",0});
        seen[stoi("0000")] = true;
        while(!qu.empty()){
            pair<string,int> current = qu.front();
            qu.pop();
            if(current.first == target) return current.second;
            for(int i = 0 ; i < 4 ; i++){
                string temp = current.first;
                char num = temp[i];
                temp[i] = (num == '9') ? '0' : (char)num+1 ;
                if(!seen[stoi(temp)]){
                    qu.push({temp,current.second+1});
                    seen[stoi(temp)] = true;
                }
                temp[i] = (num == '0') ? '9' : (char)num-1 ;
                if(!seen[stoi(temp)]){
                    qu.push({temp,current.second+1});
                    seen[stoi(temp)] = true;
                }
            }
        }
        return -1;
    }
};

int main()
{
    vector<string> input = {"0201","0101","0102","1212","2002"};
    Solution a;
    cout << a.openLock(input, "0202")<<endl;
    return 0;
}