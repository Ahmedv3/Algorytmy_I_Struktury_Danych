#include<iostream>
#include<cstdlib>
using namespace std;

long long tab[1000000];


int szukaj(int lewy, int prawy, long szukana)
{ int licznik;
	int srodek;
	while(lewy<=prawy)
	{

		srodek = (lewy + prawy)/2;
    licznik++;
		if(tab[srodek] == szukana)
    {
      cout << "liczba porownan: " <<licznik << endl;
      return srodek;
    }


		if(tab[srodek] > szukana)
			prawy = srodek - 1;
		else
			lewy = srodek + 1;
}

	return -1;
}

int main()
{
	long long n,szukana;
  cout << "podaj ilosc elementow"<< endl;
	cin>>n;

	for(int i=0;i<n;i++){
    cout << "wprowadz " << i+1 << " element: "<< endl;
  	cin>>tab[i];
  }


  cout << "Podaj szukana liczbe:" << endl;
	cin>>szukana;

	int pozycja = szukaj(0,n-1,szukana);

	if(pozycja==-1)
		cout<<"Liczba "<<szukana<<" nie występuje w zbiorze"<<endl;
	else
		cout<<"Liczba "<<szukana
<<" występuje w zbiorze w komórce o numerze "<<pozycja<<endl;
	return 0;
}
