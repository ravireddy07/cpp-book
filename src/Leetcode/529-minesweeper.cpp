// https://leetcode.com/problems/minesweeper/

#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isBomb(vector<vector<char>> &board, int i, int j)
    {
        if (i >= 0 && j >= 0 && i < board.size() && j < board[0].size() && board[i][j] == 'M')
            return true;
        else
            return false;
    }
    bool isSafe(vector<vector<char>> &board, int i, int j)
    {
        if (i >= 0 && j >= 0 && i < board.size() && j < board[0].size() && board[i][j] == 'E')
            return true;
        else
            return false;
    }
    void reveal(vector<vector<char>> &board, int i, int j)
    {
        board[i][j] = 'B';
        int cnt = 0;
        if (isBomb(board, i + 1, j))
            cnt++;
        if (isBomb(board, i - 1, j))
            cnt++;
        if (isBomb(board, i, j + 1))
            cnt++;
        if (isBomb(board, i, j - 1))
            cnt++;
        if (isBomb(board, i + 1, j + 1))
            cnt++;
        if (isBomb(board, i + 1, j - 1))
            cnt++;
        if (isBomb(board, i - 1, j + 1))
            cnt++;
        if (isBomb(board, i - 1, j - 1))
            cnt++;
        if (cnt)
        {
            board[i][j] = cnt + '0';
            return;
        }

        if (isSafe(board, i + 1, j))
            reveal(board, i + 1, j);
        if (isSafe(board, i - 1, j))
            reveal(board, i - 1, j);
        if (isSafe(board, i, j + 1))
            reveal(board, i, j + 1);
        if (isSafe(board, i, j - 1))
            reveal(board, i, j - 1);
        if (isSafe(board, i + 1, j + 1))
            reveal(board, i + 1, j + 1);
        if (isSafe(board, i + 1, j - 1))
            reveal(board, i + 1, j - 1);
        if (isSafe(board, i - 1, j + 1))
            reveal(board, i - 1, j + 1);
        if (isSafe(board, i - 1, j - 1))
            reveal(board, i - 1, j - 1);
    }

    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
    {
        if (board[click[0]][click[1]] == 'M')
        {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        reveal(board, click[0], click[1]);
        return board;
    }
};

int main()
{
    vector<vector<char>> input = {{'E', 'E', 'E', 'E', 'E'},
                                  {'E', 'E', 'M', 'E', 'E'},
                                  {'E', 'E', 'E', 'E', 'E'},
                                  {'E', 'E', 'E', 'E', 'E'}};
    vector<int> click = {3, 0};
    Solution a;
    vector<vector<char>> show = a.updateBoard(input, click);
    cout << "[";
    for (int i = 0; i < show[i].size(); i++)
    {
        cout << "[";
        for (int j = 0; j < show[j].size(); j++)
        {
            if (j == show[j].size() - 1)
            {
                cout << show[i][j];
            }
            else
            {
                cout << show[i][j] << ", ";
            }
        }
        cout << "]," << endl;
    }
    cout << "]";
    return 0;
}