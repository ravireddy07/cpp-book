// Interview Question on BridgeLabZ Solutions

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string sentance = "Happy New Year Ravi kanth Gojur";
    int wordCount = 1;
    for (int i = 0; i < sentance.size(); ++i)
        if (sentance[i] == 32)
            wordCount++;
    cout << "Number of Words: " << wordCount << "\n";

    map<char, int> result;
    for (int i = 0; i < sentance.size(); ++i)
        if (sentance[i] == 'a' or sentance[i] == 'e' or sentance[i] == 'i' or sentance[i] == 'o' or sentance[i] == 'u')
            ++result[sentance[i]];

    for (auto &i : result)
        cout << i.first << " " << i.second << "\n";
    return 0;
}
