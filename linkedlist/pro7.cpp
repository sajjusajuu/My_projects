// Mearging two sorted linkedlists without using extra memory for third list

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
	
	listnode* l1 = createlist(50);	// Creates a linkedlist of 100 nodes and returs the pointers to the first node
	listnode *l2 = createlist(50);
	/*while(l) {
		cout << l->data << " ";
		l = l->ptr;
	}*/
	
	listnode *l3, *p;
	
	if(l1->data > l2->data) {
		l3 = l2;
		l2 = l2->ptr;
	}
	else	{
		l3 = l1;
		l1 = l1->ptr;
	}
	p = l3;
	while( l1 && l2) {
		if(l1->data > l2->data) {
			p->ptr = l2;
			p = l2;
			l2 = l2->ptr;
		}
		else {
			p->ptr = l1;
			p = l1;
			l1 = l1->ptr;
		}
	}
	if(l1)
		p->ptr = l1;
	else
		p->ptr = l2;
	
	p = l3;
	while(p) {
		cout << p->data << " " ;
		p = p->ptr;
	}
	return 0;
}
	
	
