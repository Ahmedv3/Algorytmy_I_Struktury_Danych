#include <vector>
#include <iostream>

using namespace std;

bool ruch(int** tab, const int& tab_size, int wariant, int x, int y, int& pos_x, int& pos_y)
{
    // wypisanie w switchu poszczegolnych wariantow ruchu
    switch (wariant) {
        case 1:
            pos_x = x + 1;
            pos_y = y - 2;
            break;
        case 2:
            pos_x = x + 2;
            pos_y = y - 1;
            break;
        case 3:
            pos_x = x + 2;
            pos_y = y + 1;
            break;
        case 4:
            pos_x = x + 1;
            pos_y = y + 2;
            break;
        case 5:
            pos_x = x - 1;
            pos_y = y + 2;
            break;
        case 6:
            pos_x = x - 2;
            pos_y = y + 1;
            break;
        case 7:
            pos_x = x - 2;
            pos_y = y - 1;
            break;
        case 8:
            pos_x = x - 1;
            pos_y = y - 2;
            break;
    }
    // jesli wykonany ruch miesci sie w tablicy i pole jest nieodwiedzone to zwracamy prawde
    if (0 <= pos_x && pos_x < tab_size //x mieści sie w tablicy
        && 0 <= pos_y && pos_y < tab_size //y mieści sie w tablicy
        && tab[pos_x][pos_y] == 0) // pole nie było odwiedzone
        return true;
    // w przeciwnym wypadku falsz
    return false;
}

bool skoczek(int** tab, const int& tab_size, int x, int y, int ktory)
{
    int pos_x, pos_y, wariant;
    
    // ustwiamy element tablicy jako n-ty ruch
    tab[x][y] = ktory;
    
    // jesli numer ruchu jest rowny rozmiarowi tablicy
    // to znaczy ze algorytm dobiegl konca i wypisujemy wszystkie ruchy
    if (ktory == tab_size * tab_size)
    {
        for (int i = 0; i<tab_size; i++)
        {
            for (int j = 0; j<tab_size; j++)
                cout << tab[i][j] << "\t";
            cout << endl;
        }
        return true;
    }
    // w przeciwnym wypadku wykonujemy ruch
    else
    {
        // sprawdzmy po kolei wszystkie warianty w danych kroku
        for (wariant = 1; wariant<9; wariant++)
            if (ruch(tab, tab_size, wariant, x, y, pos_x, pos_y) == true)
                // jesli mozna isc dalej wywolujemy rekurencyjnie
                // funkcje skoczek az do momentu w ktorym przebedziemy juz cala
                // szachownice
                if (skoczek(tab, tab_size, pos_x, pos_y, ktory + 1) == true)
                    return true;
        tab[x][y] = 0;
    }
    
    return false;
}

void clearTab(int** tab, const int& tab_size)
{
    for (int i = 0; i<tab_size; i++)
        for (int j = 0; j<tab_size; j++)
            tab[i][j] = 0;
}




int main(int argc, const char * argv[]) {
    int max;
    cout << "Podaj rozmiar:\t";
    cin >> max;
    // tworzenie szchownicy o rozmiarze max x max
    int** tab = new int*[max];
    for (int i = 0; i<max; i++)
        tab[i] = new int[max];
    
    int start_x, start_y;
    cout << "Wpisz pole startowe (x,y) (od 0 do rozmiaru ktory wpisales -1)\t";
    cin >> start_x>> start_y;
    
    clearTab(tab, max);
    cout << "\n(" << start_x << ", " << start_y << ")\n";
    skoczek(tab, max, start_x, start_y, 1);
    
    
    cout << "Koniec!";
    
    // czyszczenie pamieci
    for (int i = 0; i < max; i++) {
        delete[] tab[i];
    }
    delete[] tab;
    
    
    std::cin.get();
    std::cin.get();
    return 0;
}