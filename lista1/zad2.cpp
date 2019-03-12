#include <iostream>
#include <limits>
#include <cmath>

double func(double x) {
	return 8 * pow(x, 5) + 3 * pow(x, 3) + 2 * pow(x, 2) + x - 6;
}

double find(double a, double b) {
	double c = a;
	do {
		c = (b + a) / 2;
		if (func(c) == 0) {
			return c;
		}
		else if (func(c) * func(a) < 0) {
			b = c;
		} else {
			a = c;
		}
	}
	while (b - a >= std::numeric_limits<double>::min());
	return c;
}

int main() {
	std::cout << find(2, 1) << std::endl;

	return 0;
}
