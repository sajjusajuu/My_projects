// To devide list into two parts one even and one odd

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
	
	listnode *l1, *l2, *temp, *l1e, *l2e;
	temp = l;
	if(temp) {
		l1 = temp;
		temp = temp->ptr;
		l1e = l1;
	}
	if(temp) {
		l2 = temp;
		temp = temp->ptr;
		l2e = l2;
	}
	bool flag = true;
	while(temp) {
		if(flag) {
			l1e->ptr = temp;
			l1e = temp;
		}
		else	{
			l2e->ptr = temp;
			l2e = temp;
		}
		flag = !flag;
		temp = temp->ptr;
	}

	l1e->ptr = l2e->ptr = NULL;
	l1e = l1;
	while(l1e) {
		cout << l1e->data << " ";
		l1e = l1e->ptr;
	}
	cout <<"\n\n";
	l2e = l2;
	while(l2e) {
		cout << l2e->data << " ";
		l2e = l2e->ptr;
	}
	return 0;
}
	
	
