#include <iostream>
using namespace std;

void GenPar(int n, int var1, int var2, string str) {
    if(closeB == n) {
        cout<<str<<endl;
        return;
    }
    if(var1 > var2) {
        GenPar(n, var1, var2+1, str+')');
    }
    if(openB < n) {
        GenPar(n, var1+1, var2, str+'(');
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    GenPar(n, 0, 0, "");
    return 0;
}
