/* This is to find the minium element of a stack in O(1) complexity with efficiently */

// Written by Sajid Hussain


#include <iostream>
#include <cstdlib>
using namespace std;

class stacknode {
	public:
	int data;
	stacknode *next;
	stacknode(int n) { data = n; }
	stacknode() { data = 0; }
};

bool isEmpty(stacknode* top) {	
	return( top == NULL );
}

void push(stacknode ** top, int val) {
	
	stacknode * temp = new stacknode(val);
	temp->next = *top;
	*top = temp;
}


int pop(stacknode **top) {
	if(*top==NULL) {
		cout << "stack is empty" << endl;
		return -1;
	}
	stacknode* temp = *top;
	*top = (*top)->next;
	int d = temp->data;
	free(temp);
	return d;
}

int peep(stacknode *top) {
	if(!top) {
		cout << "stack is empty" << endl;
		return -1;
	}
	return (top->data);
}

void print(stacknode* top) {	
	while(top) {
		cout << top->data << " ";
		top = top->next;
	}
	cout << endl;
}


int main() {
	
	stacknode *s=NULL, *sam = NULL;
	int input;
	while(1) {
		cin >> input;
		if(input <= 0)
			break;
		push(&s, input);
		if(isEmpty(sam))
			push(&sam, input);
		else {
			int top_sam = peep(sam);
			if( input <= top_sam)
				push(&sam, input);
		}
	}

	//print(s); print(sam);
	while(!isEmpty(s)) {
		cout << "The stack is ";
		print(s);
		cout << "The minimum of the stack is " << peep(sam) << endl;
		int pop_s = pop(&s);
		if(pop_s == peep(sam))
			pop(&sam);
	}
	return 0;
}
