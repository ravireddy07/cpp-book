#include <iostream>
#include <string>
using namespace std;

void lexicoLarger(string str, string osf, bool flag, string originalString) {
    if(str.size() == 0) {
        if(osf.compare(originalString)!=0)
            cout << osf << endl;
        return;
    }
    for(int i = 0; i < str.size(); i++) {
        string ros = str.substr(0, i) + str.substr(i+1);
        char ch = str[i];
        if(flag) {
            lexicoLarger(ros, osf+ch, flag, originalString);
        } else {
            if(str[i] >= str[0]) {
                lexicoLarger(ros, osf+ch, flag or ch > str[0], originalString);
            } else if(str[i] < str[0]) {
                // No call
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    string str;
    cin>>str;
    lexicoLarger(str, "", false, str);
    return 0;
}
