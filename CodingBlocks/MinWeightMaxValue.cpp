#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int main() {
    int n,input;
    cin>>n;
   Item arr[n];
   for(int i =0;i<n;i++){
       int a, b;
       cin>>a>>b;
       arr[i].weight = a;
       arr[i].weight = b;
  }

  int capacity;
  cin>>capacity;
  sort(arr, arr+n, cmp);
  double result = 0;
  double curr_weight = 0;
  for(int i=n-1;i>=0;i--){
      if(arr[i]weight+curr_weight <= capacity){
          result += arr[i].value;
          curr_weight += arr[i].weight;
      }
      else{
          int diff = capacity - curr_weight;
          double temp = diff*((double)arr[i].value/arr[i].weight);
          result+=temp;
          break;
      }
  }
  cout<<result;
   return 0;
}
