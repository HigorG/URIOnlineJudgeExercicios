#include <iostream>

using namespace std;

long long int fat (long long int n) {
	if ((n == 1) || (n == 0)) {
		return 1;
	} else {
		return fat(n-1)*n;
	}
}

int main() {
	long long int soma, M, N;

	while (cin >> M >> N) {
		soma = fat(M) + fat(N);

		cout << soma << endl;
	}

	return 0;
}