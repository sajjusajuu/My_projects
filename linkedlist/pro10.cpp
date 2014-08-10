// Joseph circle problem

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
	start = new listnode(1);
	pre = start;

	for(int i = 1; i<n; i++) { 
		pre->ptr = new listnode(i+1);
		pre = pre->ptr;
	}
	pre->ptr = start;
	return start;
}
	
		
		

int main() {
	
	
	int n;	// The total number of people in a circle

	int m;	// To kill every m'th person

	cin >> n >> m;
	
	listnode * l = createcircularlist(n);

	listnode *p = l;
	if( m == 0) {
		while( p->ptr != l)
			p = p->ptr;
	}
	else {
		while(p->ptr != p) {
			listnode *pre = p;
			for(int i = 0; i<m; i++) {
				pre = p;
				p = p->ptr;
			}
			pre->ptr = p->ptr;
			p = p->ptr;
		}
	}
	cout << "God saved "<< p->data << endl;
		
	return 0;
}
	
