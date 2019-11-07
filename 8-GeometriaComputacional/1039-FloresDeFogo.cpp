#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

typedef struct {
	int R, X, Y; 
} Circulo;

int main() {
	double distancia;
	Circulo A, B;

	while(scanf("%d %d %d %d %d %d", &A.R, &A.X, &A.Y, &B.R, &B.X, &B.Y) != EOF) {
		distancia = sqrt(pow((A.X - B.X), 2) + pow((A.Y - B.Y), 2));

		if (distancia + B.R <= A.R) {
			cout << "RICO" << endl;
		}
		else {
			cout << "MORTO" << endl;
		}
	}

	return 0;
}