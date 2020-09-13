/*
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
*/

/*cout << "[";
    for (int i = 0; i < output.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < output[0].size(); j++)
        {
            if (i == output[0].size() - 1)
                cout << output[i][j];
            else
                cout << output[i][j] << ", ";
        }
        cout << "]" << endl;
    }
    cout << "]";*/

#include <iostream>
using namespace std;

int main()
{
    string plainText = "ATTACKATDAWN";
    int grid1 = 4, grid2 = 5, val = 0, TextSize = plainText.length(), height = TextSize / grid1;
    char plainTextGrid[height][grid1], temp, CipherTextGrid[height][grid2];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < grid1; j++)
        {
            temp = plainText[val];
            val++;
            plainTextGrid[i][j] = temp;
        }
    }
    cout << "Plain text: " << endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < grid1; j++)
        {
            cout << plainTextGrid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl
         << "Resultant Cipher text will be: ";
    for (int i = 0; i < grid1; i++)
    {
        for (int j = 0; j < height; j++)
        {
            cout << plainTextGrid[j][i];
        }
    }
    cout << endl
         << endl;

    // Decryption
    val = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < grid2; j++)
        {
            if (TextSize == val)
            {
                CipherTextGrid[i][j] = '_';
            }
            else
            {
                temp = plainText[val];
                val++;
                CipherTextGrid[i][j] = temp;
            }
        }
    }
    cout << endl
         << "Cipher Text: " << endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < grid2; j++)
        {
            cout << CipherTextGrid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl
         << "Resultant Cipher text will be: ";
    for (int i = 0; i < grid2; i++)
    {
        for (int j = 0; j < height; j++)
        {
            cout << CipherTextGrid[j][i];
        }
    }
    return 0;
}