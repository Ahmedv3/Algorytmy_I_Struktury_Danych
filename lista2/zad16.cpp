#include <iostream>

struct node{
  node (int v = 0, node *p = nullptr) :
    x(v), parent(p) {}

    int x;
    node* left = nullptr;
    node* right = nullptr;
    node* parent = nullptr;


class iterator
{
private:
	node* currentNode; // wskaznik na obecny wezel

public:
	iterator(node* t) :
		currentNode(t)
	{ }
//przechodzi przez elementy w kolejnosci inorder
	iterator begin(node* t)
	{
		if(t)
		{
			while(t->left)
			{
				t = t->left;
			}
		}
		return iterator(t); //zwraca obiekt klasy iterator ostatni po lewej
	}

	iterator end(node* t)
	{
		return iterator(nullptr);
	}

	iterator& operator = (node* t)
	{
		this->currentNode = t; //zapisujemy emelent otrztmany ew argumencie
		return *this;
	}

	iterator operator ++ (int)
	{
		currentNode = nextNode(this->currentNode); // przejscie do nastepnego  elementu
		return currentNode;
	}

	bool operator != (const iterator& it)
	{
		return currentNode != it.currentNode; // sprawdza czy nasz currnode nie jest otrzymanemu currentnodowi danego obiektu.
	}

	int operator* ()
	{
		return currentNode->x; // zwraca klucz z current node
	}

	node* nextNode(node* t)
	{
		node* t1 = t; //tworzymy zmienna pomocnicza t1 do ktorej zapisujemy node'a przekazanego w agrumencie.
		if(t->right == nullptr) //dopoki right child node'a "t" jest nullem.
		{
			while(t->parent != nullptr && t1->x > t->parent->x)//dopoki parent node'a "t" nie jest nullem i klucz node'a "t1" jest wiekszy od klucza parenta node'a "t".
			{
				t = t->parent;//Przejdz do nastepnego parenta w nodzie "t"
			}
			return t->parent;// po wyjsciu z petli wihile zwroc ostatniego zapisanego parenta node'a "t"
		}
		else // jesli right child nie jest nullem.
		{
			t = t->right; //przejdz raz do right child'a node'a "t"
			while (t->left != nullptr && t->left->x > t1->x)//dopoki left child node'a "t" nie jest nullem i klucz left child'a jest wiekszy od  klucza node'a "t1".
			{
				t = t->left; // Przejdz do nastepnego left child'a w nodzie "t"
			}
		return t;// zwroc node'a "t" z ostatnim zapisanym left child'em z petli while.
		}
	}
};
};

void insert(node*& t, int x)
{
	node** current = &t;
	node** parent = nullptr;

	while(*current)
	{
		parent = current;
		if(x < (*current)->x)
		{
			current = &((*current)->left);
		}
		else
		{
			current = &((*current)->right);
		}
	}

	if(parent != nullptr)
	{
		*current = new node(x, *parent);
	}
	else
	{
		*current = new node(x);
	}

}

using namespace std;

int main(int argc, char const *argv[])
{

    node* L = nullptr;

	insert(L, 15);
	insert(L, 6);
	insert(L, 2);
	insert(L, 10);
	insert(L, 8);
	insert(L, 7);
	insert(L, 9);
	insert(L, 12);
	insert(L, 17);
	insert(L, 20);


	for(node::iterator it = it.begin(L); it != it.end(L); it++)
	{
		std::cout << *it << std::endl;
	}
    return 0;

}
