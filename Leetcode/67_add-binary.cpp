// https://leetcode.com/problems/add-binary/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int len_a = a.size(), len_b = b.size(), i = len_a - 1, j = len_b - 1, carry = 0, sum;
        string res;
        /* As in the case of addition by hand - start from LSB and move towards MSB */
        while (i >= 0 || j >= 0 || carry)
        {
            /* Only account for valid indicies - and convert to integers */
            sum = (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0) + carry;

            /* Since it is binary addition - base is 2. Convert integer to string and append at the end  */
            res += ((sum % 2) + '0');
            carry = sum / 2;
            --i;
            --j;
        }
        /* We kept appending result at the end - so the final solution requires reversal */
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution a;
    cout << a.addBinary("11", "1") << endl;
    return 0;
}