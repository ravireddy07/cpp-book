#include<iostream>
using namespace std;

int RecurTwins(string str, int temp){
     if(str[temp] == '\0' || str[temp+1] == '\0')
          return 0;
     if(str[temp] == str[temp+2])
          return 1 + RecurTwins(str, temp+1);
     return RecurTwins(str, temp+1);
}

int main()
{
     string str;
     cin>>str;
     cout<<RecurTwins(str, 0);
     return 0;
}
