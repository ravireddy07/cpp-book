#include <iostream>
using namespace std;

void binaryOnes(int n, string osf){
    if(n==0){
        cout<<osf<<endl;
        return;
    }

    binaryOnes(n-1, osf+"0");
    if(osf.size()==0 or osf[osf.size()-1]=='0'){
        binaryOnes(n-1, osf+"1");
    }
}
int main() {
    int n;
    cin>>n;
    binaryOnes(n,"");
    return 0;
}

//Advanced Example
/*
#include <iostream>
using namespace std;

void ones(int n, string osf) {
	// Base case
	if(n==0) {
		cout<<osf<<endl;
		return;
	}
	// Recursion


	ones(n-1, osf+"0");
	if(osf.size()==0 or osf[osf.size()-1]=='0') {
		ones(n-1, osf+"1");
	}
}

int main(int argc, char const *argv[])
{
	/* code *//*
	int i;
	cin>>i;
	int n[i];
	for(int j=0;j<i;j++){
	    cin>>n[j];
	}
	for(int k=0;k<i;k++){
	    int temp = n[k];
	    ones(temp, "");
	}

	return 0;
}*/
