#include<iostream>

using namespace std;

struct node  // drzewo bez wskaźnika na rodzica
{ 
	int x;
	node* left;
	node* right;
	
	node(int x0, node* l=nullptr, node* r=nullptr)
		:x(x0), left(l), right(r)
	{}
};

void insert(node *& t, int x) 
{
	node **t1=&t;
	while(*t1)
		if(x<(*t1)->x)
			t1=&((*t1)->left);
		else
			t1=&((*t1)->right);
	*t1=new node(x);
}  

int poziom(node *&t, int key)
{
	node *n = t;
	int level = 1; // wyznacznik poziomu

	while (n != nullptr && n->x != key) {
		level++;
		if (key < n->x)
			n = n->left;
		else n = n->right;
	}
	return n ? level : 0; // jesli n nie jest nullem to zwroc 0 jak nie to zwroc level 
}

int main(int argc, char const *argv[])
{


    node* t=nullptr;
        insert(t,3);
        insert(t,4); 
        insert(t,1);
        insert(t,7);
        insert(t,-4);
        insert(t,9);
        insert(t,2);

   int klucz;
   cin >> klucz;

   switch( poziom(t, klucz) )
    {
    case 0:
       cout << "Klucza " << klucz << " nie ma w drzewie.\n";
        break;
        
    case 1:
        cout << "Klucz " << klucz << " jest w korzeniu.\n";
        break;
        
        //...
    case 2:
        cout << "Klucz " << klucz << " jest w dziecku korzenia.\n";
        break;
        
    default:
        cout << "Klucz " << klucz << " jest na poziomie: "<< poziom(t, klucz)<<"\n";
        break;
    }
    
    return 0;
}

