// https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string freqAlphabets(string s)
    {
        string res;
        vector<char> one = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
        vector<char> two = {'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        int temp, n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (i + 2 <= n)
            {
                if (s[i + 2] == '#')
                {
                    temp = stoi(s.substr(i, 2));
                    res += two[temp - 10];
                    i += 2;
                }
            }

            if (s[i] == '1')
                res += one[0];
            else if (s[i] == '2')
                res += one[1];
            else if (s[i] == '3')
                res += one[2];
            else if (s[i] == '4')
                res += one[3];
            else if (s[i] == '5')
                res += one[4];
            else if (s[i] == '6')
                res += one[5];
            else if (s[i] == '7')
                res += one[6];
            else if (s[i] == '8')
                res += one[7];
            else if (s[i] == '9')
                res += one[8];
        }
        return res;
    }
};

int main()
{
    Solution a;
    cout << a.freqAlphabets("10#11#12") << endl;
    return 0;
}