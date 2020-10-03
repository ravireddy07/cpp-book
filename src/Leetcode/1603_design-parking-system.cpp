#include <bits/stdc++.h>
using namespace std;

class ParkingSystem
{
public:
    int bs, ms, ss;
    ParkingSystem(int big, int medium, int small)
    {
        bs = big;
        ms = medium;
        ss = small;
    }

    bool addCar(int carType)
    {
        if (carType == 1 && bs > 0)
        {
            bs--;
            return 1;
        }
        else if (carType == 2 && ms > 0)
        {
            ms--;
            return 1;
        }
        else if (carType == 3 && ss > 0)
        {
            ss--;
            return 1;
        }
        else
            return false;
    }
};

int main()
{
    ParkingSystem *obj = new ParkingSystem(1, 1, 0);
    cout << obj->addCar(2) << endl;
    return 0;
}