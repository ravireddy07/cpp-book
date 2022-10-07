#include <bits/stdc++.h>
using namespace std;

int main()
{
    int students = 3;
    vector<int> marks;
    vector<int> serial;
    int takeSerialinput, score;
    string result="";
    for (int i = 0; i < students; ++i){
        try_again:
        cout << "Enter "<<i+1<<"st Student Serial Number #: ";
        cin >> takeSerialinput;
        auto it = find(serial.begin(), serial.end(), takeSerialinput);
        if(it != serial.end()){
            cout << "\nSorry this serial number is already present! try again:\n";
            goto try_again;
        }
        else{
            serial.push_back(takeSerialinput);
        }
        result="";
        cin.ignore();
        getline(cin, result, '\n');
        score=0;
        for (int j = 0; j < result.size();++j){
            if(result[j] == 'T'){
                score += 2;
            }
            else if(result[j] == 'F'){
                score -= 1;
            }
        }
        marks.push_back(score);
    }

    //Displaying data
    float avgMarks=0;
    cout<<"\n\nSerial : ";
    for(auto i : serial){
        cout<<i<<" ";
    }
    cout<<"\nMarks : ";
    for(auto i : marks){
        cout<<i<<" ";
        avgMarks+=i;
    }
    
    // Finding Winner:
    int index = max_element(marks.begin(), marks.end()) - marks.begin();
    cout << "\n\nWinner student is: " << serial[index] << " with marks " << marks[index] << "\n";

    marks.erase(marks.begin() + index);
    serial.erase(serial.begin() + index);
    // Runner
    index = max_element(marks.begin(), marks.end()) - marks.begin();
    cout << "Runner up student is: " << serial[index] << " with marks " << marks[index] << "\n\n";

    cout<<"Average of Marks: "<<(float)avgMarks/students<<"\n";
    
    return 0;
}
