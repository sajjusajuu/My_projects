/* This is general implementation of a tree . This code will be used in next programs as a tool to write the logic */

// This also contains the level order traversal of a tree

// Written by Sajid Hussain



#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

class treenode  {
	public:
	int data;	
	treenode *right;
	treenode *left;
	treenode(int i) { data = i; right = left = NULL; }
};

class queuenode {
	public:
	treenode *data;
	queuenode *next;
	queuenode(treenode *p) {
		data = p;
		next = NULL;
	}
};


class queue {
	public:
	queuenode *front, *rear;
	queue() { front = rear = NULL; }
	void enque(treenode *ptr) 
		if(front == NULL) {
			front = new queuenode(ptr);
			rear = front;
		}
		else {
		rear->next = new queuenode(ptr);
		rear = rear->next;
		}
	}
	treenode * deque() {
		if(front == rear) {
			treenode *temp = front->data;
			rear = front = NULL;
			return temp;
		}
		else {
			treenode *temp = front->data;
			front = front->next;
			return temp;
		}

	}
	bool isEmpty() {
		return (!front);
	}
};


void createtree( treenode **ptr, int n) {
	if(n == 0)
		return;
	*ptr = new treenode(((float)rand()/RAND_MAX)*100);
	n--;
	int n1 = n/2;
	int n2 = n - n1;
	createtree(&((*ptr)->right), n1);
	createtree(&((*ptr)->left), n2);
}



void printusingq(treenode *root) {
	queue Q;
	int count = 0;
	Q.enque(root);
	while(!(Q.isEmpty())) {
		treenode *temp = Q.deque();
		cout << temp->data << " ";
		if(temp->left)
			Q.enque(temp->left);
		if(temp->right)
			Q.enque(temp->right);
		count++;
		if(count > 100) break;
	}
	cout << endl;
}
	

void print( treenode *root) {
	if(!root)
		return;
	else {
		cout << root->data << " ";
		print(root->left);
		print(root->right);
	}
}


int main() {
	
	treenode *root;
	createtree(&root, 50);
	print(root);
	cout << endl;
	printusingq(root);

	return 0;
}
	
	
