// Sliptting a circural linkedlist

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

listnode* createcircularlist(int n) {
	
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
	pre->ptr = start;
	return start;
}
	
		
		

int main() {
	
	listnode* l = createcircularlist(100);	// Creates a linkedlist of 100 nodes and returs the pointers to the first node

	/*while(l) {
		cout << l->data << " ";
		l = l->ptr;
	}*/
	
	listnode *p1, *p2, *p3;
	p1 = p2 = l;
	
	while(p2->ptr->ptr != l && p2->ptr != l) {
		p1 = p1->ptr;
		p2 = p2->ptr->ptr;
	}
	if( p2->ptr == l) {
		listnode *temp = p1;
		p1 = p1->ptr;
		temp->ptr = l;
		p2->ptr = p1;
	}
	else
	{
		listnode *temp = p1->ptr;
		p1->ptr = l;
		p1 = temp;
		p2->ptr->ptr = p1;
	}
	// now the two lists are l and p1

	p2 = l;
	do {
		cout << p2->data << " ";
		p2 = p2->ptr;
	} while(p2 != l);

	cout << endl;
	p2 = p1;
	
	do {
		cout << p2->data << " ";
		p2 = p2->ptr;
	} while(p2 != p1);
	
	
	return 0;
}
	
	
