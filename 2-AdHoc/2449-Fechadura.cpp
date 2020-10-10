#include <iostream>

using namespace std;

int main() {
  int N, M, movements = 0;

  cin >> N >> M;

  int P[N];

  for (int i = 0; i < N; i++) {
    cin >> P[i];
  }

  for (int i = 0; i < N - 1; i++) {
    if (P[i] != M) {
      while (P[i] != M) {
        if (P[i] < M) {
          P[i]++;
          P[i+1]++;
        } else {
          P[i]--;
          P[i+1]--;
        }
        movements++;
      }
    }
  }

  cout << movements << endl;

  return 0;
}
