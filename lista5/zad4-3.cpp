
// C++ implementation of Radix Sort :)
#include<iostream>
using namespace std;

// Funkcja pozwalająca uzyskać maksymalną wartość tab[]
int getMax(int tab[], int n)
{
    int maximum = tab[0];
    for (int i = 1; i < n; i++)
        if (tab[i] > maximum)
            maximum = tab[i];
    return maximum;
}

// Funkcja do oblicznia sposobem countingSort tablicy tab [] zgodnie z cyfrą reprezentowaną przez exp.
void countingSort(int tab[], int n, int exp)
{
    int output[n]; //to będzie nasz output
    int i, count[10] = {0};

    // Zapisz liczbę wystąpień w count[]
    for (i = 0; i < n; i++)
        count[ (tab[i]/exp)%10 ]++;

    //Zmiana count[i] więc count[i] teraz zawiera rzeczywistą pozycję tej cyfry w outpucie[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Budowanie tablicy output[]
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (tab[i]/exp)%10 ] - 1] = tab[i];
        count[ (tab[i]/exp)%10 ]--;
    }

    // Skopiuj tablicę wyjściową do tab [], aby tab [] zawierał teraz posortowane liczby według bieżącej cyfry
    for (i = 0; i < n; i++)
        tab[i] = output[i];
}

// Funkcja sortująca tab[] o rozmiarze n przy użyciu Radix Sort
void radixsort(int tab[], int n)
{
    //Znajdź maksymalną liczbę, aby poznać liczbę cyfr
    int m = getMax(tab, n);

 //Wykonanie counting sort dla każdej cyfry. Zamiast podania liczby cyfr, przekazywana jest exponenta. Exp wynosi 10 ^ i gdzie i jest bieżącą liczbą cyfr
    for (int exp = 1; m/exp > 0; exp *= 10)
        countingSort(tab, n, exp);
}

// Wypisanie tablicy
void print(int tab[], int n)
{
    for (int i = 0; i < n; i++)
        cout << tab[i] << " ";
}

//sprawdzenie powyzszych funkcji
int main()
{
    int tab[] = {1,34,123,321,432,132,543,651,91,32,987,910,643,641,12,342,498,987,965,122,121,431,350};
    int n = sizeof(tab)/sizeof(tab[0]);
    radixsort(tab, n);
    print(tab, n);
    return 0;
}



