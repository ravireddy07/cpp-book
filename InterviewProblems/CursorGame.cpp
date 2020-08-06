/*
Sample Input:                                          Sample Output:
3           # Matrix Dimension                         3
1 2 3       # data(can be strings also)
4 5 6
7 8 9
4           # Number of Moves
r           # Move name(L, R, T, B)
b
r
t
*/

#include <iostream>
using namespace std;

int main()
{
    int i = 3;
    //cin >> i;
    int mat[i][i] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    /*for (int k = 0; k < i; i++)
    {
        for (int l = 0; l < i; l++)
        {
            cin >> mat[k][l];
        }
    }*/
    int j = 4, pointerRow = 0, pointerCol = 0;
    //cin >> j;
    string move[j];
    for (int m = 0; m < j; m++)
    {
        cin >> move[m];
        if (move[m] == "l" || move[m] == "L")
        {
            pointerCol -= 1;
        }
        else if (move[m] == "r" || move[m] == "R")
        {
            pointerCol += 1;
        }
        else if (move[m] == "t" || move[m] == "T")
        {
            pointerRow -= 1;
        }
        else if (move[m] == "b" || move[m] == "B")
        {
            pointerRow += 1;
        }
        else
        {
            return 0;
        }
    }

    cout << mat[pointerRow][pointerCol] << endl;
    return 0;
}