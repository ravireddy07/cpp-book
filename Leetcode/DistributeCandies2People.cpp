/*
Test Case #1

Input: candies = 7, num_people = 4
Output: [1,2,3,1]
Explanation:
On the first turn, ans[0] += 1, and the array is [1,0,0,0].
On the second turn, ans[1] += 2, and the array is [1,2,0,0].
On the third turn, ans[2] += 3, and the array is [1,2,3,0].
On the fourth turn, ans[3] += 1 (because there is only one candy left), and the final array is [1,2,3,1].


Test Case #2

Input: candies = 10, num_people = 3
Output: [5,2,3]
Explanation: 
On the first turn, ans[0] += 1, and the array is [1,0,0].
On the second turn, ans[1] += 2, and the array is [1,2,0].
On the third turn, ans[2] += 3, and the array is [1,2,3].
On the fourth turn, ans[0] += 4, and the final array is [5,2,3].
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        vector<int> candiesDistributed(num_people, 0);
        int i = 0;
        //while there are still candies to give out
        while (candies > 0)
        {
            //give every person according to his turn (incremented by one every turn)
            candiesDistributed[i % num_people] += i + 1;
            //update number of candies left
            candies -= i + 1;
            i++;
        }
        //incase we gave an extra candy to last person (so if there are less than 0 candies left we decrement last person's candies otherwise candies = 0 so nothing changes)
        candiesDistributed[(i - 1) % num_people] += candies;

        return candiesDistributed;
    }
};

int main()
{
    Solution a;
    vector<int> show;
    show = a.distributeCandies(7, 4);
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