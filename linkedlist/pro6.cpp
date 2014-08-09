// To find the common node in two linked lists which intersect at a point.

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

void createintersectinglists(int n1, int n2, int n3, listnode **l1, listnode **l2) {
	
	*l1 = createlist(n1);
	*l2 = createlist(n2);

	listnode* e1, *e2, *L1, *L2, *temp;

	e1 = *l1;
	e2 = *l2;

	while(e1) { L1 = e1; e1 = e1->ptr; }
	while(e2) { L2 = e2; e2 = e2->ptr; }

	temp = createlist(n3);

	L1->ptr = L2->ptr = temp;

}

int main() {
	
	//listnode* l = createlist(100);	// Creates a linkedlist of 100 nodes and returs the pointers to the first node

	/*while(l) {
		cout << l->data << " ";
		l = l->ptr;
	}*/
	
	listnode *l1, *l2, *p1, *p2;

	createintersectinglists(10, 5,  15, &l1, &l2);
	
	int len1 = 0, len2 = 0;
	p1 = l1;

	while(p1) { len1++; p1 = p1->ptr; }
	p1 = l2;

	while(p1) { len2++; p1 = p1->ptr; }
	int d;
	if( len1 > len2) {
		p1 = l1;
		p2 = l2;
		d = len1 - len2;
	}
	else {
		p1 = l2;
		p2 = l1;
		d = len2 - len1;
	}
	int count = d;
	while(d--)
		p1 = p1->ptr;
	while(p1 != p2) {
		p1 = p1->ptr;
		p2 = p2->ptr;
		count++;
	}
	cout << "They intersect at " << count <<endl;
	return 0;
}
