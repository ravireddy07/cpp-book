#include <iostream>
#include <cmath>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
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
} myobject;


int main() {
	//code
	int num_tests = 0;
    cin >> num_tests;
    if(num_tests == 0){
    		cout << 0 << endl;
    		return 0;
    }

	for(int i = 0; i < num_tests; ++i ){        // do this num test times
	    int N = 0;
	    int X = 0;
	    int Y = 0;
	    vector <set> set_vector;
	    int total_tips = 0;
	    cin >> N;
	    cin >> X;
	    cin >> Y;

	    int temp = 0;
 	    for (int j = 0; j < N; ++j){            // get worker A input N times
 	        cin >> temp;
 	        set t(temp);
 	        set_vector.push_back(t);
 	    }

 	    for (int k = 0; k < N; ++k){            // get worker B input and fill out the abs difference N times
 	        cin >> temp;
 	        set_vector.at(k).b = temp;
 	        set_vector.at(k).diff = set_vector.at(k).a - temp;
 	    }

// 	    // TEST: print out the entire vector
// 	    for(int z = 0; z < N; ++z){
// 	    		cout << "A's tip: " << set_vector.at(z).a << endl;
// 	    		cout << "B's tip: " << set_vector.at(z).b << endl;
// 	    		cout << "abs_diff: " << set_vector.at(z).diff << endl;
// 	    }
 	    // vector is filled

 	    //crappy selection sort

// 	    for(int i = 0; i < N-1; ++i){
// 	    		int max = i;
// 	    		for(int j = i+1; j < N; ++j){
// 	    			if( abs(set_vector.at(j).diff) > abs(set_vector.at(max).diff)){
// 	    				max = j;
// 	    			}
// 	    		}
// 	    		swap(set_vector.at(i), set_vector.at(max));
// 	    }

 	    // std sort
 	   sort (set_vector.begin(), set_vector.end(), myobject);

 	   // 	    // TEST: is it in max according to abs diff
//  	    	    for(int z = 0; z < N; ++z){
//  	    	    		cout << "A's tip: " << set_vector.at(z).a << endl;
//  	    	    		cout << "B's tip: " << set_vector.at(z).b << endl;
//  	    	    		cout << "abs_diff: " << set_vector.at(z).diff << endl;
//  	    	    }
 	    int curr = 0;
 	    while(X > 0 && Y > 0 && curr < N){
 	    		if(set_vector.at(curr).diff > 0){
 	    			total_tips += set_vector.at(curr).a;
 	    			--X;
//  	    		 	cout << "given to X, total: " << total_tips << endl;
 	    		}
 	    		else{
 	    			total_tips += set_vector.at(curr).b;
 	    			--Y;
//  	    		 	cout << "given to Y, total: " << total_tips << endl;
 	    		}
 	    		++curr;
 	    }
//  	    cout << "curr: " << curr << endl;

 	   // now either X or Y or neither will be > 0
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
