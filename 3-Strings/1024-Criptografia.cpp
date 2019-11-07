#include <iostream>
#include <algorithm> // Para o reverse()
#include <string> // Tipo string

using namespace std;

int main() {
	int N;
	string texto;

	cin >> N;

	cin.ignore(); // Equivalente ao fflush(stdin)

	for (int i = 1; i <= N; i++) {
		getline(cin, texto);

		// Primeira passada
		for (int j = 0; j < texto.length(); j++) {
			if (((texto.at(j) >= 65) && (texto.at(j) <= 90)) || ((texto.at(j) >= 97) && (texto.at(j) <= 122))) {
				texto.at(j) += 3;
			}
		}

		// Segunda passada
		reverse(texto.begin(), texto.end());

		// Terceira passada
		int metade = (texto.length() / 2);

		for (int j = metade; j < texto.length(); j++) {
			texto.at(j) -= 1;
		}

		cout << texto << endl;
	}

	return 0;
}