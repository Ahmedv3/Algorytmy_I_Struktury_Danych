#include<iostream>

using namespace std;

struct lnode
{
    int key;
    lnode *next;
    lnode(int n = 0, lnode *l = nullptr) : key(n), next(l) {};
};

void print(lnode *L)
{
    while (L != nullptr)
    {
        cout << L->key << "  ";
        L = L->next;
    }
    cout << endl;
}

lnode* merge(lnode* L1, lnode* L2)
{
	lnode *temp;
  	lnode *L = new lnode();
  	temp = L;

  	while (L1 && L2)
  	{
    	if (L1->key > L2->key)
    	{
      		temp->next = L2;
      		L2 = L2->next;
    	}
    	else {
			temp->next = L1;
     	 	L1 = L1->next;
    	}
    	temp = temp->next;
  	}

  	while (L1)
  	{
    	temp->next = L1;
    	L1 = L1->next;
    	temp = temp->next;
  	}

  	while (L2)
  	{
    	temp->next = L2;
    	L2 = L2->next;
    	temp = temp->next;
  	}

  	temp = L;

  	if (temp)
  	{
    	L = temp->next;
    	delete temp;
  	}

  	return L;
}

int getLength(lnode* L)
{
    int length = 0;

    while (L)
    {
        ++length;
        L = L->next;
    }

    return length;
}

void mergeSort(lnode*& L)
{
    
    int i, j; //zmienne pomocnicze do forów, i sie przyda pozniej
    
    int length = getLength(L); //zapisujemy dlugosc listy
    
    lnode* sorted[length + 1]; //by nie operowac na oryginalnej liscie, tworze kolejna liste
    for (i = 0; i < length; ++i) //przepisujemy nasza liste do listy "pomocniczej"
    {
        
        sorted[i] = L; //ta pozycja w sroted = bierze aktualny "l"
        
        L = L->next; //idz do nastepnego: "l"
        
        sorted[i]->next = nullptr; //tworze nulla dla nastepnego, puste miejsce 
    }
    
    int mid = length; //potrzebny do srodka 
    sorted[i] = nullptr;  //ostatni element listy ma miec nulla w next 
    
    while (mid > 1) //dopoki mid jest wieksze od 1
    {
        
        for(i = j = 0; i < mid; i += 2, ++j) //petla ktora sortuje i wstawia do listy uporzadkowany element.
        {
            sorted[j] = merge(sorted[i], sorted[i+1]);
        }
            
        mid = (mid + 1) / 2; // dzielimy nasz srodek na pol
    }

L = sorted[0]; //start listy
}


int main()
{
    lnode *l = nullptr;

    l = new lnode(7, l);
	l = new lnode(13, l);
    l = new lnode(2, l);
	l = new lnode(33, l);
    l = new lnode(2, l);
	l = new lnode(21, l);
	l = new lnode(-3, l);

   cout << "Lista nieposortowana: \n";
   print(l);
   mergeSort(l);
   cout << "Lista posortowana: \n";
   print(l);

    return 0;
}