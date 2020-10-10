#include <iostream>

using namespace std;

int main() {
  int N, LA, LB, SA, SB;

  cin >> N >> LA >> LB >> SA >> SB;

  bool isPossible = ((N >= LA && N <= LB) && (N >= SA && N <= SB));

  if (isPossible) {
    cout << "possivel" << endl;
  } else {
    cout << "impossivel" << endl;
  }

  return 0;
}
