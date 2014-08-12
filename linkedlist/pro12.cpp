// to clone a list of two pointer, one next and random pointer in O(n) time and O(1) space complexity.

// Written by Sajid Hussain, ISM DhanBad.



#include <iostream>
#include <cstdlib>
using namespace std;


class listnode {
	public:
	int data;
	listnode * ptr;
	listnode *rptr;
	listnode(int n) { data = n;  ptr = NULL; rptr = NULL;}
	listnode() { data = 0; ptr = NULL; rptr = NULL ;}
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
	

void fillrandom(listnode* l) {
	listnode* start = l;
	while(l->ptr->ptr->ptr) {	
		l->rptr = l->ptr->ptr->ptr;
		l = l->ptr;
	}
	while(l) {
		l->rptr = start;
		l = l->ptr;
		start = start->ptr;
	}
}	

int main() {
	
	listnode* l = createlist(20);	// Creates a linkedlist of 20 nodes and returs the pointers to the first node

	/*while(l) {
		cout << l->data << " ";
		l = l->ptr;
	}*/
	fillrandom(l);
	listnode* temp = l, *temp2;
	while(temp) {
		temp2 = new listnode();
		temp2->data = temp->data;
		temp2->ptr = temp->rptr;
		temp->rptr = temp2;
		temp = temp->ptr;
		
	}
	temp = l;
	while(temp) {
		temp2 = temp->rptr;
		temp2->rptr = temp2->ptr->rptr;
		temp = temp->ptr;
		
	}
	temp = l;
	listnode* l2 = l->rptr;
	while(temp) {
		temp2 = temp->rptr;
		temp->rptr = temp2->ptr;
		temp2->ptr = temp->ptr==NULL? NULL: temp->ptr->rptr ;
		temp = temp->ptr;
		
	}
	temp = l;
	while(temp)	{
		cout << temp->data << " " << temp->rptr->data << endl;
		temp = temp->ptr;
	}
	cout << "\nNew List:\n" ;
	temp = l2;
	while(temp)	{
		cout << temp->data << " " << temp->rptr->data << endl;
		temp = temp->ptr;
	}
	return 0;
}
	
	
