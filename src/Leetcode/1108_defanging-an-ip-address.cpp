// https://leetcode.com/problems/defanging-an-ip-address/

#include <iostream>
using namespace std;

class Solution
{
public:
    string defangIPaddr(string address)
    {
        string res = "";
        for (int i = 0; i < address.length(); i++)
        {
            if (address[i] == '.')
                res += "[.]";
            else
                res += address[i];
        }
        return res;
    }
};

int main()
{
    Solution a;
    cout << a.defangIPaddr("1.1.1.1") << endl;
    return 0;
}