#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int size = 255;
	int *asciiTable = new int[size];
	for (int i = 0; i < size; i++) {
		asciiTable[i] = 0;
	}
	char i;
	fstream fin("ascii.txt", fstream::in);
	while (fin >> noskipws >> i) {
		asciiTable[int (i)]++;
	}
	return 0;
}
