#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> result;
        for (int i = 1; i <= n; i++)
        {
            if (i % 3 == 0 and i % 5 == 0)
                result.push_back("FizzBuzz");
            else if (i % 5 == 0)
                result.push_back("Buzz");
            else if (i % 3 == 0)
                result.push_back("Fizz");
            else
                result.push_back(to_string(i));
        }
        return result;
    }
};

int main()
{
    Solution a;
    vector<string> show;
    show = a.fizzBuzz(15);
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
    return 0;
}