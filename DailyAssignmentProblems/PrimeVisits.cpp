#include <iostream>
using namespace std;
bool isPrime(int num){
    if(num<=0) return false;
    if(num==1) return false;
    if(num==2) return true;
    if((num&1)==0) return false;

    bool isPrime=true;
    for (int i = 3; i*i <=num ; i+=2) {
        if(num%i==0){
            isPrime=false;
            break;
        }
    }
    return isPrime;
}
int main() {
    int t;
    cin >> t;

    while(t--){
        int a,b;
        cin >> a>>b;

        int primes[b+1];
        primes[0]=0;
        primes[1]=0;

        for (int i = 2; i <= b; i++){
            if((i&1)==0||i<a){
                primes[i]=0;
            }else{
                primes[i]=1;
            }
        }
        if(2>=a){
            primes[2]=1;
        }
        for (int i = 3; i <=b; i+=2) {

            int j=2;
            while(i*j<=b){
                primes[i*j]=0;
                j++;
            }
        }

        int count=0;
        for (int i = 0; i <=b; i++) {
            if(primes[i]){
                count++;
            }
        }

        cout << count <<endl;
    }
}
