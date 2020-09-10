// https://leetcode.com/problems/bulls-and-cows/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int a[128]{0}, b[128]{0}, n = secret.size(), t1 = 0, t2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
                t1++;
            else
            {
                if (b[secret[i]])
                {
                    t2++;
                    b[secret[i]]--;
                }
                else
                    a[secret[i]]++;
                if (a[guess[i]])
                {
                    t2++;
                    a[guess[i]]--;
                }
                else
                    b[guess[i]]++;
            }
        }
        return to_string(t1) + "A" + to_string(t2) + "B";
    }
};

int main()
{
    Solution a;
    cout << a.getHint("1807", "7810") << endl;
    return 0;
}