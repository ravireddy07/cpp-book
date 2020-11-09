#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> real = {"ate", "eat", "tan", "ate", "nat", "ban"};
    vector<string> sortedArray = real;
    vector<string> output;
    vector<int> visited;
    int ok = 0;
    for (int i = 0; i < sortedArray.size(); i++)
    {
        output.erase(output.begin(), output.end());
        ok = 0;
        for (int l = 0; l < visited.size(); l++)
        {
            if (visited[l] == i)
            {
                ok = 1;
                break;
            }
        }
        if (ok)
            continue;
        output.push_back(real[i]);
        for (int j = i + 1; j < sortedArray.size(); j++)
        {
            sort(sortedArray[i].begin(), sortedArray[i].end());
            sort(sortedArray[j].begin(), sortedArray[j].end());
            if (sortedArray[i] == sortedArray[j])
            {
                output.push_back(real[j]);
                visited.push_back(j);
            }
        }
        cout << "[";
        for (int i = 0; i < output.size(); i++)
        {
            if (i == output.size() - 1)
                cout << output[i];
            else
                cout << output[i] << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}
