/*

Sample Input:                Sample Output:
babba                        2 7

*/

#include <iostream>
#define ll long long
using namespace std;

int main()
{
    string word;
    cin >> word;
    int n = word.size();
    ll odd = 0, even = 0;
    int pos = 0, next = 0;
    for (int i = 0; i < n; i++)
    {
        next = (pos + 1) % 2;
        odd += val[word[i] - '0'][pos];
        even += val[word[i] - '0'][next];
        odd++;
        val[word[i] - '0'][pos]++;
        pos = next;
    }
    cout << even << " " << odd << endl;

    return 0;
}