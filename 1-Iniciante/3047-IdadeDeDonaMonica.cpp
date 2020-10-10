#include <iostream>

using namespace std;

int main() {
  int M, A, B;

  cin >> M >> A >> B;

  int thirdSon = M - A - B;

  if (A >= B && A >= thirdSon) {
    cout << A << endl;
  } else if (B >= A && B >= thirdSon) {
    cout << B << endl;
  } else {
    cout << thirdSon << endl;
  }

  return 0;
}
