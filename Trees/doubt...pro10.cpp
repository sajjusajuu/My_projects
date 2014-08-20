// Given an algorithm to find the diameter of a tree!!!

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
	void enque(treenode *ptr) {
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
	treenode *peep() {
		if(front == NULL)
			return NULL;
		else
			return front->data;
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
	Q.enque(root);
	Q.enque(NULL);
	while(!(Q.isEmpty())) {
		treenode *temp = Q.deque();
		if(temp == NULL) {
			if(!Q.isEmpty()) {
				Q.enque(NULL);
				cout << endl;
				continue;
			}
			else
				break;
		}
		cout << temp->data << " ";
		if(temp->left)
			Q.enque(temp->left);
		if(temp->right)
			Q.enque(temp->right);
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

bool areIdentical(treenode *root1,treenode *root2) {
	if(root1 == NULL && root2 == NULL)
		return true;
	else if((root1 == NULL && root2 != NULL) || (root2 == NULL && root1 != NULL))
		return false;
	else	{
		if( areIdentical( root1->left, root2->left) && areIdentical( root1->right, root2->right))
			return true;
		else
			return false;
	}
}


int main() {
	
	treenode *root1, *root2;
	createtree(&root1, 50);
	createtree(&root2, 50);

	if(areIdentical( root1, root2))
		cout << "Yes they are identical" <<endl;
	else
		cout << "Not Identical" << endl;
	
	return 0;
}
	
	
