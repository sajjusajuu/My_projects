/* This is a simple array based implementation of Stack and this will be used as a basis of many future problems*/

// Written by Sajid Hussain


#include <iostream>
#include <cstdlib>
using namespace std;

class stack {
	int top;
	unsigned int capacity;
	int * array;
	public:
	stack(int n) {
		capacity = n;
		array = new int[n];
		top = -1;
	}
	stack() {
		capacity = 100;
		array = new int[100];
		top = -1; // If nothing is passed as an argument then it creates a stack of 100 elements
	}
	bool isFull();
	bool isEmpty();
	void push(int);
	int pop();
	int peek();
	void print();
};

bool stack:: isFull() {
	return( (capacity - 1) == top);
}

bool stack::isEmpty() {
	return( top == -1);
}

void stack::push(int val) {
	if(this->isFull()) 
		cout << "Stack is full cannot push" <<endl;
	else {
		top += 1;
		array[top] = val;
	}
}

int stack::pop() {
	if(this->isEmpty())
		cout << "Cannot pop because the stack is empty" <<endl;
	else 
		return array[top--];
}

int stack::peek() {
	if(this->isEmpty())
		cout << "Cannot pop because the stack is empty" <<endl;
	else 
		return array[top];
}

void stack::print() {
	for(int i = 0; i<=top; i++)
		cout << array[i] << " ";
	cout << endl;
}

int main() {
	

	stack st;
	for(int i = 0; i<20; i++)
		st.push(i);
	st.print();
	for(int i = 0; i<5; i++)
		st.pop();
	st.print();
	return 0;
}

