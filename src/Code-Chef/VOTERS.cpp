#include <bits/stdc++.h>
using namespace std;

int main()
{
    int firstSize, secondSize, thirdSize;
    scanf("%d %d %d", &firstSize, &secondSize, &thirdSize);

    std::set<int> first, second, third, output;
    int temp;
    for (int k = 0; k < firstSize; k++)
    {

        scanf("%d", &temp);
        first.insert(temp);
    }
    for (int k = 0; k < secondSize; k++)
    {
        scanf("%d", &temp);
        second.insert(temp);
    }
    for (int k = 0; k < thirdSize; k++)
    {
        scanf("%d", &temp);
        third.insert(temp);
    }

    std::set<int>::iterator setIter;
    for (setIter = first.begin(); setIter != first.end(); setIter++)
        if (second.find(*setIter) != second.end() || third.find(*setIter) != third.end())
            output.insert(*setIter);

    for (setIter = second.begin(); setIter != second.end(); setIter++)
        if (third.find(*setIter) != third.end())
            output.insert(*setIter);

    printf("%ld\n", output.size());

    for (setIter = output.begin(); setIter != output.end(); setIter++)
        printf("%d\n", *setIter);

    puts("");
    return 0;
}
