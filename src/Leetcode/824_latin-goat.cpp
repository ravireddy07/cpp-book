// Problem statement:  https://leetcode.com/problems/goat-latin/

// Leet Code Disscusion Thread: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3429/discuss/801081/C++-Simple-Brute-Force-Method-0ms-100-or-Simple-Understanding-or-Just-do-what-is-asked

/*
Test Case #1:
Input: "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"

Test Case #2:
Input: "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> split(string str, string token)
    {
        vector<string> result;
        while (str.size())
        {
            int index = str.find(token);
            if (index != string::npos)
            {
                result.push_back(str.substr(0, index));
                str = str.substr(index + token.size());
                if (str.size() == 0)
                    result.push_back(str);
            }
            else
            {
                result.push_back(str);
                str = "";
            }
        }
        return result;
    }

    string toGoatLatin(string S)
    {
        vector<string> a;
        int count = 0, ll, checkVowel;
        string temp, rule1 = "ma", rule3 = "a", result;
        char f;
        a = split(S, " ");
        for (int i = 0; i < a.size(); i++)
        {
            temp = a[i];
            f = temp[0];
            checkVowel = (f == 'a' || f == 'e' || f == 'i' || f == 'o' || f == 'u' || f == 'A' || f == 'E' || f == 'I' || f == 'O' || f == 'U');
            if (checkVowel)
            {
                temp.append(rule1);
                count++;
            }
            else
            {
                ll = temp.length();
                for (int k = 0; k < ll - 1; k++)
                {
                    temp[k] = temp[k + 1];
                }
                temp[ll - 1] = f;
                temp.append(rule1);
                count++;
            }

            for (int d = 0; d < count; d++)
            {
                temp.append(rule3);
            }

            if (i == 0)
            {
                result.append(temp);
            }
            else
            {
                result.append(" ");
                result.append(temp);
            }
        }
        return result;
    }
} a;

int main()
{
    string show;
    string s = "I speak Goat Latin";
    show = a.toGoatLatin(s);

    cout << show;
    return 0;
}
