#include <iostream>

using namespace std;

int licznik = 0;

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

lnode* merge(lnode* L1, lnode* L2) {
    lnode* resultL = nullptr;
    if (L1 == nullptr) { // jesli lista 1 jest pusta to zwroc L2
		licznik++;
        return (L2);
    }
    if (L2 == nullptr) { // jesli lista 2 jest pusta to zwroc L1
		licznik++;
        return (L1);
    }

    if (L1 -> key <= L2 -> key) { // jesli pierwsza lista jest wieksza lub rowna drogiej daj na początek resultL
		licznik++;
        resultL = L1;
        resultL -> next = merge(L1 -> next, L2); //  przypisujemy nast elementowi resultL nastepny porownany element 2 list
    } else {
		licznik++;
        resultL = L2;
        resultL -> next = merge(L1, L2 -> next);
    }
    return (resultL);
}

int main(){
	lnode *L1 = nullptr;
    lnode *L2 = nullptr;


	for (int i=0; i<4; i++)
    {
        insert(L1, i);
        insert(L2, i*5);
    }
    cout << "Lista 1" << endl;
    display(L1);
    cout << endl <<"Lista 2" << endl;
    display(L2);

    lnode* L3 = merge(L1, L2);
    cout << endl <<"Lista koncowa" << endl;
    display(L3);
    cout << endl << "licznik: " << licznik << endl;
	return 0;
}
