#include <bits/stdc++.h>
using namespace std;

int op_increase(int i) { return ++i; }

int main()
{
    vector<int> foo;
    vector<int> bar;

    // set some values:
    for (int i = 1; i < 6; i++)
        foo.push_back(i * 10); // foo: 10 20 30 40 50

    bar.resize(foo.size()); // allocate space

    transform(foo.begin(), foo.end(), bar.begin(), op_increase);
    // bar: 11 21 31 41 51

    // std::plus adds together its two arguments:
    transform(foo.begin(), foo.end(), bar.begin(), foo.begin(), std::plus<int>());
    // foo: 21 41 61 81 101

    cout << "foo contains:";
    for (auto it : foo)
        cout << ' ' << it;
    cout << '\n';
    return 0;
}
