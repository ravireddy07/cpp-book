#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        vector<int> v;
        for (int i = 0; i < word.size(); i++)
        {
            if (int(word[i]) >= 65 and int(word[i]) <= 92)
            {
                v.push_back(i);
            }
        }
        if (v.size() == 1)
        {
            if (v[0] == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (v.size() == 0)
        {
            return true;
        }
        else if (v.size() == word.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    string input = "USA";
    Solution a;
    cout << a.detectCapitalUse(input);
    return 0;
}
