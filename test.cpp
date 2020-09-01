#include <iostream>
#include <vector>
using namespace std;

std::ostream &bold_on(std::ostream &os)
{
    return os << "\e[1m";
}

std::ostream &bold_off(std::ostream &os)
{
    return os << "\e[0m";
}

int main()
{
    std::cout << bold_on << "bold" << bold_off << " non-bold" << std::endl;
}