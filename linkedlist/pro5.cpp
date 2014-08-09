// To reverse a singly linked list

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
	
	listnode* l = createlist(11);	// Creates a linkedlist of 10 nodes and returs the pointers to the first node

	/*while(l) {
		cout << l->data << " ";
		l = l->ptr;
	}*/
	
	listnode * t1 = NULL, *t2;

	// A very small and efficient way to reverse
	while(l) {		
		t2 = l;
		l = l->ptr;
		t2->ptr = t1;
		t1 = t2;
	}
	l = t2;

	while(l) {
		cout << l->data << " ";
		l = l->ptr;
	}

	return 0;
}
	
	
