// Reversing the lists in pairs
// Example > 1-2-3-4-5-6   =   2-1-4-3-6-5

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
	
	listnode* l = createlist(100);	// Creates a linkedlist of 100 nodes and returs the pointers to the first node

	/*while(l) {
		cout << l->data << " ";
		l = l->ptr;
	}*/
	
	listnode *p = l, *temp;

	if( l->ptr) {
		temp = l;
		l = l->ptr;
		temp->ptr = l->ptr;
		l->ptr = temp;
	}	
	p = l->ptr;
	while(((p->ptr) != NULL) && (((p->ptr)->ptr)!=NULL)) {
		temp = p->ptr;
		p->ptr = p->ptr->ptr;
		temp->ptr = p->ptr->ptr;
		p->ptr->ptr = temp;
		p = temp;
	}
	p = l;
	while(p) {
		cout << p->data << " ";
		p = p->ptr;
	}

	return 0;
}
	
	
