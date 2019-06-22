#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll cnt=0;
bool canimove(int row,int col,int enRow,int enCol){
    if(row<=enRow && col<=enCol)
        return true;
    return false;
}
bool Mazepathcnt(int stRow,int stCol,int enRow,int enCol,char board[],int j){
    if(stRow>=enRow && stCol>=enCol){
        cnt++;
        return false;
    }

    bool istrue=canimove(stRow+1,stCol,enRow,enCol);
    if(istrue){
        board[j]='V';
        bool IsSuccess1=Mazepathcnt(stRow+1,stCol,enRow,enCol,board,j+1);
        if(IsSuccess1){
            return true;
        }
    }
    bool IsTrue2=canimove(stRow,stCol+1,enRow,enCol);
    if(IsTrue2){
        board[j]='H';
        bool IsSuccess2=Mazepathcnt(stRow,stCol+1,enRow,enCol,board,j+1);
        if(IsSuccess2){
            return true;
        }
    }
    if(stRow==stCol){
    bool IsTrue3=canimove(stRow+1,stCol+1,enRow,enCol);
    if(IsTrue3){
        board[j]='D';
        bool IsSuccess3=Mazepathcnt(stRow+1,stCol+1,enRow,enCol,board,j+1);
        if(IsSuccess3){
            return true;
        }
    }
    }
    board[j]='0';
    return false;

}
bool Mazepath(int stRow,int stCol,int enRow,int enCol,char board[],int j){
    if(stRow>=enRow && stCol>=enCol){
        for(int i=0;i<j;i++)
            cout<<board[i];
        cout<<" ";
        return false;
    }
    bool istrue=canimove(stRow+1,stCol,enRow,enCol);
    if(istrue){
        board[j]='V';
        bool IsSuccess1=Mazepath(stRow+1,stCol,enRow,enCol,board,j+1);
        if(IsSuccess1){
            return true;
        }
    }
    bool IsTrue2=canimove(stRow,stCol+1,enRow,enCol);
    if(IsTrue2){
        board[j]='H';
        bool IsSuccess2=Mazepath(stRow,stCol+1,enRow,enCol,board,j+1);
        if(IsSuccess2){
            return true;
        }
    }
 if(stRow==stCol){
 bool IsTrue3=canimove(stRow+1,stCol+1,enRow,enCol);
    if(IsTrue3){
        board[j]='D';
        bool IsSuccess3=Mazepath(stRow+1,stCol+1,enRow,enCol,board,j+1);
        if(IsSuccess3){
            return true;
        }
    }
 }
    board[j]='0';
    return false;

}


int main()
{
    int n1;
    cin>>n1;
    char board[100];
    for(int i=0;i<100;i++){
        board[i]='0';
    }
    Mazepathcnt(0,0,n1-1,n1-1,board,0);
    Mazepath(0,0,n1-1,n1-1,board,0);
    cout<<endl<<cnt;
    return 0;
}
