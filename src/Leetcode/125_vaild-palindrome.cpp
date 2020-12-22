#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0, j = s.size();

        while (i < j)
        {
            // skip the non-alpha numeric chars
            while (i < j && !isalnum(s[i]))
                ++i;
            while (j > i && !isalnum(s[j]))
                --j;

            if (tolower(s[i]) != tolower(s[j]))
                return false;

            ++i, --j;
        }
        return true;
    }
};

int main()
{
    Solution a;
    cout << a.isPalindrome("A man, a plan, a canal: Panama") << endl;
    return 0;
}
