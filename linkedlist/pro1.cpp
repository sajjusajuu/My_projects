/* This is a prerequisite for any problems on linkedlist. This dicumentation contains the essential tools for creating a linked list*/

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
	
	

	
	return 0;
}
	
	
