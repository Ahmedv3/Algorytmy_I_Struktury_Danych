#include <iostream>
#include <cmath>

using namespace std;

double P (int k, int n, double p) {
	double res = 0;
	double q = 1 - p;
	double p_q = p / q;
	double w = pow(q, n);
	for (int i = 1; i <= n; i++) {
		res += w;
		w = w * (n--) / i * p_q;
	}
	return res;
}

int main() {
	std::cout << P(3, 10, 0.1);

	return 0;
}
