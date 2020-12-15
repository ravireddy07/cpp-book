/*
Problem Satatement:

You are given N red pieces of candy and M blue pieces of candy.
Write a program to find the number of arrangements of candy
in which not more than K pieces of the same color are placed next to each other.

Sample Test cases:

Input format:
N M K

Case-1:             output:

 1 1 1                2

Case-2:             output:

 2 1 1                1

*/

/*
Approach:

If M and N both less than K ans is direct (M+N)!/ (M! * N!)
else if one of them is bigger than K ,say M ,
then consider k+1 Red candies to be together and consider them as a bunch,
now ,find the number of ways for this (Standard P & C), and subtract from total.

if both M and N are greater than K ,then bunch only K+1 reds first,
subtract the number of ways from total,then only K+1 blues,subtract from total,
then K+1 reds and K+1 blues together ,add to total.(Principle of inclusion and exclusion)

*/

// Solution with different approach
#include <bits/stdc++.h>
using namespace std;

int limit_red = 0;
int limit_blue = 0;

int test(int total, int red, int blue, int r, int b)
{
    if ((red + blue) == 0)
        return 1;
    int x = 0;
    if (red > 0 && r > 0)
        x = test(total - 1, red - 1, blue, r - 1, limit_blue);

    int y = 0;
    if (blue > 0 && b > 0)
        y = test(total - 1, red, blue - 1, limit_red, b - 1);
    return x + y;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m, k;
        scanf("%n%m%k", &n, &m, &k);
        limit_blue = k;
        limit_red = k;
        cout << test(n + m, n, m, k, k) << "\n";
    }
    return 0;
}
