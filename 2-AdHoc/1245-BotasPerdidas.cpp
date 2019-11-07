#include <iostream>

using namespace std;

int main() {
	int N;

	while (cin >> N) {
		int tamanho[N], cont = 0;
		char lado[N];

		for (int i = 0; i < N; i++) {
			cin >> tamanho[i] >> lado[i];
		}

		for (int i = 0; i < N; i++) {
			int botaAtual = i;

			for (int j = i + 1; j < N; j++) {
				if ((tamanho[i] == tamanho[j]) && (lado[i] != lado[j]) && ((lado[i] == 'E') || (lado[i] == 'D')) && ((lado[j] == 'E') || (lado[j] == 'D'))) {
					cont++;
					tamanho[i] = -i;
					tamanho[j] = -j;
					lado[i] = '$';
					lado[j] = '$';
				}
			}
		}
		cout << cont << endl;
	}

	return 0;
}