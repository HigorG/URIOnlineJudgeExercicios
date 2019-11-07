#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

int main() { 
  int r;

  cin >> r; 
  cout << fixed << setprecision(3) << "VOLUME = " << (4.0 * 3.14159 *r*r*r)/3 << endl;

  return 0;
}
