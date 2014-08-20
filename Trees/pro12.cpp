// Finding the least common ancester of two nodes

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
	
// preorder traversal
void print( treenode *root) {
	if(!root)
		return;
	else {
		cout << root->data << " ";
		print(root->left);
		print(root->right);
	}
}

// print all root to leaf paths
void parlp(treenode *root, int arr[], int i) {
	if(root == NULL)
		return;
	if(root->left == NULL && root->right == NULL) {
		arr[i] = root->data;
		i++;
		for(int j = 0; j<i; j++)
			cout << arr[j] << " ";
		cout << endl;
	}
	else
	{
		arr[i] = root->data; i++;
		parlp( root->left, arr, i);
		parlp( root->right, arr, i);
	}
}

int findancester(treenode *root,  int a, int b) {
	if( root == NULL) 
		return -1;
	if( root->data == a || root->data == b)
		return root->data;
	int lft = findancester(root->left, a, b);
	int rit = findancester(root->right, a, b);
	if(lft && rit)
		return root->data;
	else
		lft?lft:rit;
}
	


int main() {
	
	treenode *root = NULL;
	createtree(&root,63);
	print(root);
	cout << endl;
	int a = 27, b=40;
	cout << "The least common ancester of "<<a<<" and "<<b<<" is "<<findancester(root, a, b)<<endl;
	return 0;
}
	
	
