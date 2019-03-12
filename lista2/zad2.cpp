#include <iostream>

using namespace std;


int tab[1000000];
int licznik1, licznik2, licznik3  =0;

int max(const int t[], int n){
  int x = t[n];
  while(n--){
    licznik1++;
    if(x < t[n]){
      x = t[n];
    }
  }
//  cout << "Ilosc porownan: " << licznik1 << endl;
  return x;
}

int max2(const int t[], int n){
  if(n == 1){
  //  cout << "Ilosc porownan: " << licznik2 << endl;
    return t[0];
  }
  int max = max2(t,n-1);
  licznik2++;
  if(max > t[n-1]){
  //  cout << "Ilosc porownan: " << licznik2 << endl;
    return max;
  }
  else {
  //  cout << "Ilosc porownan: " << licznik2 << endl;
    return t[n-1];
  }
}

int max3(const int t[], int pierwszy, int ostatni){
  if(pierwszy == ostatni){
  //  cout << "Ilosc porownan: " << licznik3 << endl;
    return t[ostatni];
  }
  int polowa = (pierwszy * ostatni) /2;
  int max1 = max3(t, pierwszy, polowa);
  int max2 = max3(t, polowa+1, ostatni);
  licznik3++;
  if(max1 > max2){
  //  cout << "Ilosc porownan: " << licznik3 << endl;
    return max1;
  }
  else{
  //  cout << "Ilosc porownan: " << licznik3 << endl;
    return max2;
  }
}

int main(int argc, char const *argv[]) {

  int n;
  cout << "podaj ilosc elementow"<< endl;
  cin>>n;

  for(int i=0;i<n;i++){
    cout << "wprowadz " << i+1 << " element: "<< endl;
    cin>>tab[i];
  }

  cout << max(tab, n) << endl;
  cout << max2(tab, n) << endl;
  cout << max3(tab, tab[0], tab[n-1]) << endl;

}
