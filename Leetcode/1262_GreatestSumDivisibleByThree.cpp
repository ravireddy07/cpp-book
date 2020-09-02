// https://leetcode.com/problems/greatest-sum-divisible-by-three/

#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    
    int maxSumDivThree(vector<int>& nums) {
        int mm = 3; // mm is the generalized form. In this case, mm=3
        vector<vector<int>> dp(nums.size(),vector<int>(mm,0));
        dp[0][nums[0] % mm] = nums[0]; // base case
        
        for(int i=1;i<nums.size();++i){
           for(int mod=0;mod<mm;++mod){
               int transit = mod-nums[i] % mm;
               transit = transit>=0?transit:transit+mm;
			   // you can simplify this part to one simple max, but I'm sticking with if-statements
               if(dp[i-1][transit] != 0)
                  dp[i][mod] = max(dp[i-1][mod],dp[i-1][transit]+nums[i]);
               else 
                  dp[i][mod] = nums[i] % mm == mod? max(dp[i-1][mod],nums[i]):dp[i-1][mod]; 
           }
        }
        return dp[nums.size()-1][0];
    }
};
*/

class Solution {
    int  find(vector<int>& nums,int n,int i,int sum,int dp[nums.size()][4]) {
        if(i==n){
            if(sum==0){
                return 0;
            }
            return -1;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int a =  find(nums,n,i+1,(sum+nums[i])%3,dp);      // consider the element in total sum
        if(a!=-1){                                         // the condition ssay we are having solution with given element
            a = a + nums[i];                             
        }
        int b = find(nums,n,i+1,sum,dp);              // don't have to consider the element in total sum
        dp[i][sum] = max(a,b);                     // track the max of above to recursion condition
        return dp[i][sum];
    }
public:
    int maxSumDivThree(vector<int>& nums) {
        int max = 0,sum=0;        //initialize the max_value to track max value divisble by 3
        if(nums.size()==1){
            if(nums[0]%3==0){
                return nums[0];
            }
            return 0;
        }
        int n = nums.size();
        int dp[n][4];      
        for(int i=0;i<n;i++){
            for(int j=0;j<4;j++){
                dp[i][j] = -1;              //initialize the dp value to -1 to check wheather the value exist or not
            }
        }
        max = find(nums,n,0,sum,dp);
        if(max==-1){
            return 0;
        }
        return max;
    }
};

int main()
{
    Solution a;
    vector<int> input = {3,6,5,1,8};
    cout << a.maxSumDivThree(input) << endl;
    return 0;
}
