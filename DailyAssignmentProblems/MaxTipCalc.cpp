#include<iostream>
#include<cmath>
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

class set {
public:
	set(int a);
	int a;
	int b;
	int diff;
};

set::set(int a){
	this->a = a;
	this->b = 0;
	this->diff = 0;
}

struct myclass {
  bool operator() (set i, set j) { return (abs(i.diff) > abs(j.diff));}
}myobject;


int main() {
	int num_tests = 0;
	cin>>num_tests;
	if(num_tests == 0) {
		cout<<0<<endl;
		return 0;
	}

	for(int i = 0;i<num_tests;++i ) {
		int N = 0,X = 0,Y = 0;
		vector<set> set_vector;
		int total_tips = 0;
		cin>>N>>X>>Y;

		int temp = 0;
		for(int j=0;j<N;++j) {
			cin>>temp;
			set t(temp);
			set_vector.push_back(t);
		}

 	    for (int k = 0; k < N; ++k){
 	        cin >> temp;
 	        set_vector.at(k).b = temp;
 	        set_vector.at(k).diff = set_vector.at(k).a - temp;
 	    }

 	   sort (set_vector.begin(), set_vector.end(), myobject);
		 int curr = 0;
 	    while(X > 0 && Y > 0 && curr < N){
 	    		if(set_vector.at(curr).diff > 0){
 	    			total_tips += set_vector.at(curr).a;
 	    			--X;
 	    		}
 	    		else{
 	    			total_tips += set_vector.at(curr).b;
 	    			--Y;
 	    		}
 	    		++curr;
 	    }
 	   while(X > 0 && curr < N){
 		  total_tips += set_vector.at(curr).a;
 		  --X;
 		  ++curr;
 	   }
  	   while(Y > 0 && curr < N){
  		  total_tips += set_vector.at(curr).b;
  		  --Y;
  		  ++curr;
  	   }
 	   cout << total_tips << endl;
	}
	return 0;
}
