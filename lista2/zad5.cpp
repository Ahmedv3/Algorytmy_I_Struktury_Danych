#include <iostream>

using namespace std;

struct lnode {
    int key;
    lnode *next;
    lnode(int key0, lnode* nxt=nullptr)
        :key(key0), next(nxt)
    {}
};

void insert(lnode*& t, int key) {
    lnode **t1 = &t;
    while (*t1)
        t1=&((*t1)->next);
    *t1 = new lnode(key);
}

void display(lnode *t, char z1 = ' ', char z2 = ' ') {
    if (t) {
        std::cout << z1;
        display(t->next, '(',')');
        std::cout << t -> key;
        std::cout << z2;
    }
}

void reverse(lnode*& L) {
    if (L) { // dopóki są elementy tablicy
        lnode* current = L; // current staje sie nasza lista przekazana przez L
        lnode* next = NULL;
        lnode* prev = NULL;

        while (current != NULL) {
            next = current -> next; // pod 'next' zostaje przypinasy wskaźnik na nastepny element listy.
            current -> next = prev; // odwrócenie wskaźnika ustawiając go na 'prev'
            prev = current; // przypisuje wartość prev do current (przejscie do nast elementu) poprzedni = teraźniejszy
            current = next; //  teraźniejszy = poprzedni
        }
        L = prev; // odwrócenie wskaźnika na nowy element który jest pierwszy 
    }
}


int main(){

	lnode *L1 = nullptr;

	for (int i=0; i<4; i++)
    {
        insert(L1, i);
    }

    display(L1);
    reverse(L1);
    display(L1);
	return 0;
}
