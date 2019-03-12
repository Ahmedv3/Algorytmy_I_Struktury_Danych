#include <iostream>

using namespace std;

int licznik;

struct node  // drzewo bez wskaźnika na rodzica
{ 
	int x;
	node* left;
	node* right;
	
	node(int x0, node* l=NULL, node* r=NULL)
		:x(x0), left(l), right(r)
	{}
};

void insert(node *& t, int x) // wstawianie (nierekurencyjna)
{
	node **t1=&t;
	while(*t1)
		if(x<(*t1)->x){
			t1=&((*t1)->left);
			licznik++;
		}
			
		else {
			t1=&((*t1)->right);
			licznik++;
		}
			
	*t1=new node(x);
} 

int h(node* t) // wysokość drzwa BST
{
	return !t ? 0 : 1+std::max(h(t->left),h(t->right));
}

void display(node *t,char z1=' ',char z2=' ') 
{
	if(t)
	{
		std::cout<<z1;
		display(t->left,'(',')');
		std::cout<<t->x;
		display(t->right,'[',']');
		std::cout<<z2;
	}
}



int main(){
	
	node *N = nullptr;
	int n = 0;
	cin >> n;
	for (int i=1; i<=n; i++){
        insert(N, i);
    }
    
    display(N);
    std::cout << "\nGłębokość drzewa: " << h(N) << std::endl;
	std::cout << "Ilość porównań: " << licznik << std::endl;
	//Złożoność pamieciowa i obliczeniowa to n^2 w najgorszym wypadku beda 2 porownania na kazda liczbe. 
	return 0;
}
