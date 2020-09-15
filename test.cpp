/*
cout << "[";
    for (int i = 0; i < show.size(); i++)
    {
        if (i == show.size() - 1)
        {
            cout << show[i];
        }
        else
        {
            cout << show[i] << ", ";
        }
    }
    cout << "]";
*/

/*cout << "[";
    for (int i = 0; i < output.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < output[0].size(); j++)
        {
            if (i == output[0].size() - 1)
                cout << output[i][j];
            else
                cout << output[i][j] << ", ";
        }
        cout << "]" << endl;
    }
    cout << "]";*/

#include <iostream>
#include <string>
#include <unistd.h>
#include <bits/stdc++.h>

using namespace std;

class word
{
    template <class T>
    class MyVector
    {
    public:
        typedef T *iterator;
        MyVector();
        iterator begin();
        iterator end();
        int size();
        iterator insert(iterator position, const T &item);

    private:
        T items[1000];
        int used;
    };
};

int main(int argc, char **argv)
{
    enum
    {
        total,
        unique
    } mode = total;

    for (int c; (c = getopt(argc, argv, "tu")) != -1;)
    {
        switch (c)
        {
        case 't':
            mode = total;
            break;
        case 'u':
            mode = unique;
            break;
        }
    }
    argc -= optind;
    argv += optind;
    string word;

    int count = 0;
    vector<string> lis;
    while (cin >> word)
    {
        count++;
        int duplicate = 0;
        for (int i = 0; i < lis.size(); i++)
            if (lis[i] == word)
                duplicate = 1;
        if (!duplicate)
            lis.push_back(word);
    }

    switch (mode)
    {
    case total:
    {
        cout << "Total: " << count << '\n';
        break;
    }
    case unique:
    {
        cout << "Unique: " << lis.size() << '\n';
        break;
    }
    }
    return 0;
}