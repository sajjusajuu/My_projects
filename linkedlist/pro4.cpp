// To insert a node in a sorted linked list

// Written by Sajid Hussain, ISM DhanBad.



#include <iostream>
#include <cstdlib>
using namespace std;


class listnode {
	public:
	int data;
	listnode * ptr;
	listnode(int n) { data = n;  ptr = NULL;}
	listnode() { data = 0; ptr = NULL; }
};

listnode* createlist(int n) {
	
	listnode * start = NULL;
	listnode *pre = NULL;
	if(n == 0)
		return start;
	start = new listnode(0);
	pre = start;
	for(int i = 1; i<n; i++) { 
		pre->ptr = new listnode(i);
		pre = pre->ptr;
	}
	return start;
}
	
		
		

int main() {
	
	listnode* l = createlist(10);	// Creates a linkedlist of 10 nodes and returs the pointers to the first node

	/*while(l) {
		cout << l->data << " ";
		l = l->ptr;
	}*/
	listnode *start = l;
	listnode * ins = new listnode;
	cout << "Enter the data of the inserting node" << endl;
	
	cin >> ins->data;

	listnode * pre = l;
	if( l == NULL)
		l = ins;
	else if( l->data > ins->data) {
		ins->ptr = start;
		start = ins;
	}
	else
	{
		while(l->ptr && (l->ptr)->data <= ins->data )
			l = l->ptr;
	
		ins->ptr = l->ptr;
		l->ptr = ins;
	}
	while(start) {
		cout << start->data << " ";
		start = start->ptr;
	}
	return 0;
}
