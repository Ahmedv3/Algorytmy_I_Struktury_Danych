#include <iostream>
#include <random>

using namespace std;

struct node  // drzewo bez wskaźnika na rodzica
{ 
	int x;
	node* left;
	node* right;
	
	node(int x0, node* l=NULL, node* r=NULL)
		:x(x0), left(l), right(r)
	{}
};

int h(node* t) // wysokość drzwa BST
{
	return !t ? 0 : 1+std::max(h(t->left),h(t->right));
}

void insert(node *& t, int x) // wstawianie (nierekurencyjna)
{
	node **t1=&t;
	while(*t1)
		if(x<(*t1)->x){
			t1=&((*t1)->left);
		}
			
		else {
			t1=&((*t1)->right);
		}
			
	*t1=new node(x);
}

void display(node *t,char z1=' ',char z2=' ') // in order z nawiasami 
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
	
	node *L = nullptr;
	
	std::mt19937 gen{
		std::random_device{}()
		};
    std::uniform_int_distribution<int> generate{0,100};
    
    for (auto i=0; i<10; i++)
    {
        int r = generate(gen);
        insert(L, i);
        std::cout << r << " ";
    }
    std::cout << "\nWysokość to: " << h(L) << std::endl;
    
    display(L);
	
	return 0;
}
