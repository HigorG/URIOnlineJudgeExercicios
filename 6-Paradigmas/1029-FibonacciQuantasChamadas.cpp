#include <iostream>

using namespace std;

int chamadas;

int fibo(int num) {
	chamadas++;
	if (num == 0) {
		return 0;
	} else {
		if (num == 1) {
			return 1;
		} else {
			return fibo(num - 1) + fibo(num - 2);
		}
	}
}

int main() {
	int X, N;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> X;
		
		cout << "fib(" << X << ") = " << chamadas - 1 << " calls = " << fibo(X) << endl;
		chamadas = 0;
	}

	return 0;
}