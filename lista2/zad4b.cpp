#include <iostream>

using namespace std;

void odwroc(int *tab, int pocz, int kon){
  int tmp;

  while(pocz < kon){
    tmp = tab[pocz];
    tab[pocz] = tab[kon];
    tab[kon] = tmp;
    pocz++;
    kon--;
  }
}

void przesun(int *tab, int n, int k){
  odwroc(tab,0,n-1); // odwrocenie calej tablicy
  odwroc(tab,0,k-1); // odwracamy ta czesc ktora chcemy przesunac
  odwroc(tab,k,n-1); // odwracamy pozostala czesc talicy.
}

int main(){

  

  return 0;
}
