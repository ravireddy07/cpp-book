#include <bits/stdc++.h>
using namespace std;

long long int Modular(long long int a, long long int b, long long int c)
{
  long long int result = 1;
  while (b > 0)
  {
    if (b & 1)
      result = (result * a) % c;
    a = (a * a) % c;
    b = b >> 1;
  }
  return result;
}

int main()
{
  long long int a, b, c;
  cin >> a >> b >> c;
  cout << Modular(a, b, c) << "\n";
}
