#include <iostream>
#include <cmath>

using namespace std;

int sito(){

  int liczba, i, j, pierwiastek, *tablica;
cout << "Podaj maksimum: ";
cin >> liczba;

pierwiastek = (int)sqrt((double)liczba);
tablica = new int[liczba+1];
for (i = 0; i <= liczba; i++)
tablica[i] = i;

for (i = 2; i <= pierwiastek; i++)
{
if (tablica[i] != 0)
for (j = 2*i; j <= liczba; j+= i)
tablica[j] = 0;
}

cout << "Liczby pierwsze z przedzialu <2," << liczba << "> to:\n";
for (i = 2; i <= liczba; i++)
if (tablica[i] != 0)
cout << tablica[i] << " ";
cout << endl;
}

int main(int argc, char const *argv[]) {
  sito();
  return 0;
}
