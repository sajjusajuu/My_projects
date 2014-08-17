// To see a linked list is a palindrom or not!!!

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
	int c;
	cin>>c;
	start = new listnode(c);
	pre = start;
	for(int i = 1; i<n; i++) { 
		cin >> c;
		pre->ptr = new listnode(c);
		pre = pre->ptr;
	}
	return start;
}
	
		
		

int main() {
	
	listnode* l = createlist(10);	// Creates a linkedlist of 10 nodes and returs the pointers to the first node

	listnode* t = l;


	while(t) {
		cout << t->data << " ";
		t = t->ptr;
	}

	cout << endl;
	listnode* l1 = l, *l2 = l, *tem = l;


	while(l2 && l2->ptr) {
		tem = l1;
		l1 = l1->ptr;
		l2 = l2->ptr->ptr;
	}
	listnode* temp;
	if(!(l2)) {
		temp = l1;
		tem->ptr = NULL;
	}
	else {
		temp = l1->ptr;
		l1->ptr = NULL;
	}
	l1 = temp;
	listnode * t1 = NULL, *t2;

	t = l;
	while(t) {
		cout << t->data << " ";
		t = t->ptr;
	}
	cout << endl;
	t = l1;
	while(t) {
		cout << t->data << " ";
		t = t->ptr;
	}
	cout << endl;

	// A very small and efficient way to reverse
	while(l1) {		
		t2 = l1;
		l1 = l1->ptr;
		t2->ptr = t1;
		t1 = t2;
	}
	l1 = t2;
	while(l && l1) {
		if(l->data == l1->data) {
			l1 = l1->ptr;
			l = l->ptr;
		}
		else
			break;
	}
	t = l;
	while(t) {
		cout << t->data << " ";
		t = t->ptr;
	}
	cout << endl;
	t = l1;
	while(t) {
		cout << t->data << " ";
		t = t->ptr;
	}
	if(l || l1)
		cout << "Not a palindrom" << endl;
	else
		cout << "Is a palindrom" <<endl;

	return 0;
}
