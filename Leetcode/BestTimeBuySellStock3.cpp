#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int profit, result = 0, buyP = 0, sellP = 0, tran = 0, index = 0;
    bool buy = true, sell = true;
    int ar[prices.size()];
    ar[0] = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        profit = 0;
        buyP = prices[i];
        buy = false;
        sell = true;
        for (int j = i + 1; j < prices.size(); j++)
        {
            sellP = prices[j];
            if (buyP < sellP && profit < (sellP - buyP))
            {
                profit = sellP - buyP;
                cout << "buyed: " << buyP << endl;
                cout << "selled: " << prices[j] << endl;
                cout << "profit: " << profit << endl;
            }
        }
        ar[index] = profit;
        cout << "Current Profit: " << profit;
        cout << endl
             << endl;
    }
    for (int k = 0; k < sizeof(ar) / sizeof(ar[0]); k++)
    {
    }
    return result;
}

int main()
{
    vector<int> arr = {3, 3, 5, 0, 0, 3, 1, 4};
    int r = maxProfit(arr);
    cout << "Max Profit: " << r;
    return 0;
}