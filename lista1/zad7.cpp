#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

std::vector<int> product(std::vector<int> a , std::vector<int> b) {
	std::vector<int> c(a.size() + b.size() - 1);
	for (int i = 0; i < c.size(); i ++) {
		c[i] = 0;
	}
	for (int i = 0; i < b.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			c[i+j] = c[i+j] + a[i] * b[j];
		}
	}
	return c;
}

std::vector<int> readPoly(string file) {
	string text;
	ifstream myFile;
	myFile.open(file.c_str());
	myFile >> text;

	std::vector<int> polyVec;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] != ',') {
			char a = text[i];
			polyVec.push_back((int)a - 48);
		}
	}
	return polyVec;
}

void writeFile(std::vector<int> polyVec, string file) {
	ofstream myFile;
	myFile.open(file.c_str());
	for (int i = 0; i < polyVec.size(); i++) {
		string x = std::to_string(polyVec[i]);
		if (i != polyVec.size() - 1) {
			myFile << x + ",";
		} else {
			myFile << x;
		}
	}
	myFile.close();
}

int main() {
	std::vector<int> wek1 = readPoly("a.txt");
	std::vector<int> wek2 = readPoly("b.txt");
	std::vector<int> wek3 = product(wek1, wek2);
	for (int i = 0; i < wek3.size(); i++) {
		std::cout << wek3[i] << std::endl;
	}
	writeFile(wek3, "c.txt");
}
