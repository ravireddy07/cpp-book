// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        int word_index = 1, i = 0, j = 0;
        while (i < sentence.length())
        {
            while ((j < searchWord.length()) && (sentence[i] == searchWord[j]) && (i >= j) && ((i - j == 0) || (sentence[i - 1 - j] == ' ')))
            {
                j++;
                i++;
            }
            if (j == searchWord.length())
                return word_index;
            if (sentence[i] == ' ')
                word_index++;
            j = 0;
            i++;
        }
        return -1;
    }
};

int main()
{
    Solution a;
    cout << a.isPrefixOfWord("this problem is an easy problem", "pro") << endl;
    return 0;
}