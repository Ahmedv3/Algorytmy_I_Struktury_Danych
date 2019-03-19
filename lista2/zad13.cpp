#include <iostream>

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

void inorder_do(node *t, void f(node * x))
{
    if(t)
    {
        inorder_do(t->left, f);
        f(t); //
        inorder_do(t->right, f);
    }
}

int main(int argc, char const *argv[]) {

  return 0;
}
