#include<iostream>
#include<vector>
using namespace std;

/*
Time Complexcity: O(K*K)   Space Complexcity: O(K*K)

vector<int> getRow(int rowIndex) {
    vector<vector<int>>ans(rowIndex+1);
    for (int i=0;i<=rowIndex;i++) {
        ans[i].resize(i+1);
        ans[i][0] = ans[i][i] = 1;
        for (int j=1;j<i;j++) {
            ans[i][j] = ans[i-1][j-1]+ans[i-1][j];
        }
    }
    return ans[rowIndex];
}
*/

/*
Time Complexcity: O(K*K)  Space Complexcity: O(2*K)

vector<int> getRow(int rowIndex) {
    vector<int>ans, temp;
    for (int i = 0;i<=rowIndex;i++) {
        temp.resize(i+1);
        temp[0] = temp[i] = 1;
        for (int j=1;j<i;j++)temp[j] = ans[j-1] + ans[j];
        ans = temp;
    }
    return ans;
}
*/

/*
Time Complexcity: O(K*K)      Space Complexcity: O(K)

vector<int> getRow(int rowIndex) {
    vector<int> ans(rowIndex+1, 0);
    ans[0] = 1;
    for (int index=1; index<rowIndex+1; index++)
        for (int j=index; j>=1; j--)
            ans[j] += ans[j-1];
    return ans;
}
*/

/* Time Complexcity: O(K)   Space Complexcity: O(K) */

vector<int> getRow(int rowIndex) {
    vector<int> ans(rowIndex+1);
    ans[0] = 1;
    for (int index=1; index<rowIndex+1; index++)
        ans[index]=(long)ans[index-1]*(rowIndex-index+1)/index;
    return ans;
}


int main() {
    int n;
    cin>>n;
    vector<int> result = getRow(n);
}