#include <iostream>

double oblicz(double a[], int n, double x) {
	int res = a[0];
	int licz = 0;
	for (int i = 1; i < n; i++) {
		res = res * x + a[i];
		licz++;
	};
	return licz;
}

int main() {
	double pol[5] = { 3.1, 3.3, 5.3, -2.2, 8.4 };
	std::cout << (pol, 5, 2) << std::endl;
	return 0;
}
