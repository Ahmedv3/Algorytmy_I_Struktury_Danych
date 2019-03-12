#include <iostream>

using namespace std;

struct node
{
	int key;
	node *next;


	node(int key0, node* nxt=nullptr)
			:key(key0), next(nxt)
	{}
};


int nty(int n, node* x) {
	int newN = 1;
	while(x != nullptr){
		if(newN == n){
			return x ->key;
		}
		else{
			newN++;
			x = x -> next;
		}
	}
	return 0;
}

int main() {

	node trzeci(3);
	node drugi(2, &trzeci);
	node pierwszy(1, &drugi);


	cout << nty(1,&pierwszy) << endl;
	cout << nty(2,&pierwszy) << endl;
	cout << nty(3,&pierwszy) << endl;
	cout << nty(4,&pierwszy) << endl;
	return 0;
}
