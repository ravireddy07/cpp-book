#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'mostActive' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY customers as parameter.
 */
bool isther(string s, vector<string> ss);

vector<string> mostActive(vector<string> customers) {
    vector <string> ar;
    int n;
    cin>>n;
    double percent = 5, temp=0;
    int count=0;
    int num[customers.size()];
    for(int i=0;i<customers.size();i++) {
        count=0;
        for(int j=0;j<customers.size();j++) {
            if(customers[i] == customers[j] && isther(customers[i], ar)) {
                count++;
            }
        }
        num[ar.size()]=count;
        ar.push_back(customers[i]);
    }

    for(int k=0;k<sizeof(num)/sizeof(num[0]);k++) {
        if(((num[k]/n)/100) <= percent) {
            ar[k].pop_back();
        }
    }
    return ar;
}

bool isther(string s, vector<string> ss) {
    if(ss.size() == 0) {
        return true;
    }

    for(int i=0;i<ss.size();i++) {
        if(s == ss[i]) {
            return true;
        }
    }
    return false;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string customers_count_temp;
    getline(cin, customers_count_temp);

    int customers_count = stoi(ltrim(rtrim(customers_count_temp)));

    vector<string> customers(customers_count);

    for (int i = 0; i < customers_count; i++) {
        string customers_item;
        getline(cin, customers_item);

        customers[i] = customers_item;
    }

    vector<string> result = mostActive(customers);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
