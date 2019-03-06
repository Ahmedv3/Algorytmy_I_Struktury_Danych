#include <iostream>
#include <cmath>
using namespace std;

class ulamek {

public:
  int licznik;
  int mianownik;

  ulamek (int licznik_, int mianownik_){
    licznik = licznik_;
    mianownik = mianownik_;
  }

  int nwd(unsigned int a,unsigned int b)
  {
    if(a == 0 || b == 0){
      return 1;
    }
    else{
      while(a!=b)
         if(a>b)
             a-=b;
         else
             b-=a;
      return a;
    }

  }

  ulamek operator+ (ulamek b){
    ulamek c(0,0);
    c.mianownik = mianownik * b.mianownik;
    c.licznik = b.licznik * mianownik + licznik * b.mianownik;

    int cNWD = nwd(c.licznik,c.mianownik);
    c.licznik /= cNWD;
    c.mianownik /= cNWD;

    return c;
  }

  ulamek operator- (ulamek b){
    ulamek c(0,0);
    c.licznik = (licznik * b.mianownik) - (b.licznik * mianownik);
    c.mianownik = mianownik * b.mianownik;

    int cNWD = nwd(abs(c.licznik),abs(c.mianownik));
    c.licznik /= cNWD;
    c.mianownik /= cNWD;
    return c;
  }

  ulamek operator* (ulamek b){
    ulamek c(0,0);
    c.licznik = b.licznik * licznik;
    c.mianownik = mianownik * b.mianownik;
    int cNWD = nwd(c.licznik,c.mianownik);
    c.licznik /= cNWD;
    c.mianownik /= cNWD;
    return c;
  }

  ulamek operator/ (ulamek b){
    ulamek c(0,0);
    c.mianownik = mianownik * b.licznik;
    c.licznik = b.mianownik * licznik;

    int cNWD = nwd(c.licznik,c.mianownik);
    c.licznik /= cNWD;
    c.mianownik /= cNWD;
    return c;
  }


};

std::ostream & operator <<(std::ostream & wyjscie, ulamek & b){
  return wyjscie << b.licznik << '/'  << b.mianownik << endl;
}

istream & operator >> (istream & wejscie, ulamek &b)
{
    int n, d;
    wejscie >> n;
    char c;
    wejscie >> c;
    if (c == '/')
        wejscie >> d;
    else
    {
        wejscie.putback(c);
        d = 1;
    }
    b = ulamek(n, d);
    return wejscie;
}

int main(int argc, char const *argv[]) {

  ulamek a(0,0);
  cout << "Liczba pierwsza:" << endl;
  cin >> a;
  ulamek b(0,0);
  cout << "Liczba druga:" << endl;
  cin >> b;

  ulamek c = a + b;
  ulamek d = a - b;
  ulamek e = a * b;
  ulamek f = a / b;
  cout <<"Dodawanie: "<< c;
  cout << "Odejmowanie: "<<d;
  cout <<"Mnozenie: "<<e;
  cout <<"Dzielenie: " <<f;
  return 0;
}
