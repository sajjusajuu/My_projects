// This is to find the span array of another array;
// Ex: if suppose array is 6 3 4 5 2 then span array will be 1 1 2 3 1



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

int peek(stacknode *top) {
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
	
	stacknode* top = NULL;
	for(int i = 0; i<20; i++)
		push(&top, i+1);
	print(top);
	for(int i = 0; i<10; i++)
		pop(&top);
	print(top);
	return 0;
}
