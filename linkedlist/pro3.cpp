// Written by Sajid Hussain, ISM DhanBad.

// This is also called Floyed cycle finding algorithm along with returning the node where loop starts

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
	
listnode* createcycliclist(int n, int c) {
	
	if( n < c || c <= 0) {
		cout << "Not possible" << endl;
		return NULL;
	}
	if(n == 0)
		return NULL;

	listnode * start = NULL;
	listnode *pre = NULL;
	listnode *cptr = NULL;
	int count = 1;
	start = new listnode(0);
	pre = start;
	for(int i = 1; i<n; i++) {
		if( count == c)
			cptr = pre; 
		pre->ptr = new listnode(i);
		pre = pre->ptr;
		count++;
	}
	pre->ptr = cptr;
	return start;
}
		

int main() {
	
	listnode* l = createcycliclist(100, 40);// Creates a linkedlist of 100 nodes and returs the pointers to the first node
	
	//listnode *l = createlist(100); 


	/*for(int i = 0; i< 150; i++) {
		cout << l->data << " " ;
		l = l->ptr;
	}*/
	
	listnode * slowptr = l, *fastptr = l;
	bool loop = false;
	int count = 1;
	while(fastptr->ptr && (fastptr->ptr)->ptr)  {
		slowptr = slowptr->ptr;
		fastptr = (fastptr->ptr)->ptr;
		if( slowptr == fastptr) {
			cout << "Yes, There is a loop in the linkedlist" << endl;
			loop = true;
			slowptr = l;
			while( slowptr != fastptr) {
				slowptr = slowptr->ptr;
				fastptr = fastptr->ptr;
				count++;
			}
			fastptr = fastptr->ptr;
			while( fastptr != slowptr)	{
				fastptr = fastptr->ptr;
				count++;
			}
			cout << "The lenght of linked list is " << count << endl;
			break;
		}
	}
	if( loop == false)
		cout << "No the loop do not exists" << endl;
	return 0;
}
	
	
