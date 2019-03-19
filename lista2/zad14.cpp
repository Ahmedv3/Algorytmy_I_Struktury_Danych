#include <iostream>

using namespace std;
struct node{
  node (int v = 0, node *p = nullptr) :
    x(v), parent(p) {}

    int x;
    node* left = nullptr;
    node* right = nullptr;
    node* parent = nullptr;
};

void inorder_do(node *root, void f(node*))
{
    bool leftdone = false;

    while (root)
    {
        // Jesli nie przeszlismy przesz wszystkie elementy po lewej stronie to
        // znajdz left najbardziej polewej (na samym dole)
        if (!leftdone)
        {
            while (root->left){
              root = root->left; // przechodz jak najdalej w lewo
            }
        }

      f(root); // wykonaj na nim funkcje

        // zaznacz left jako zrobione
        leftdone = true;

        // jesli right child istnieje:
        if (root->right)
        {
            leftdone = false; // zmien leftdone na false
            root = root->right;  //idzo o jedno w prawo i dalej left w dol
        }
        // Jesli rChild nie istenie, przejdz do parenta
        else if (root->parent) // jesli root ma parenta
        {
            // jesli przeslzismy przesz wszystkie elementy lewe to przejdz wyzej do parenta i przejdz przez prawe elementy
            while (root->parent && root == root->parent->right){ // jesli root ma paretna i ten parent ma right
              root = root->parent; // przejdz do nast perenta
            }

            if (!root->parent){ // jesli root nie ma parenta to przerwij
              break;
            }
            root = root->parent;
        }
        else{
          break;
        }
    }
}


int main(int argc, char const *argv[]) {


  return 0;
}
