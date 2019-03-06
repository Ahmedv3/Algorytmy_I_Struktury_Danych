#include <iostream>

using namespace std;


long long potega(long long podstawa, int wykladnik){
  long long wynik = 1;

  while(wykladnik > 0){
    if(wykladnik%2 == 1) { wynik *= podstawa; }

    podstawa *= podstawa;
    wykladnik /= 2;
  }

  return wynik;
}

long long potega_rekurencyjnie(long long podstawa, int wykladnik){
  if(wykladnik == 0) {return 1;}

  if(wykladnik%2 == 1) // gdy wykladnik nieparzysty
  {
    return podstawa * potega_rekurencyjnie(podstawa,wykladnik-1);
  }

  return potega_rekurencyjnie(podstawa,wykladnik/2) * potega_rekurencyjnie(podstawa,wykladnik/2);
}

int main(int argc, char const *argv[]) {

  cout << "Iteracyjnie: "<< potega(2,10) << endl;
  cout <<"Rekurencyjnie: " <<potega_rekurencyjnie(2,10) << endl;
  return 0;
}
