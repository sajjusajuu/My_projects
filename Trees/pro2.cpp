// To find the max element of a tree

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

void print( treenode *root) {
	if(!root)
		return;
	else {
		cout << root->data << " ";
		print(root->left);
		print(root->right);
	}
}

int findmax(treenode *root) {
	if(root == NULL)
		return -1;
	else {
		int left_max = findmax(root->left);
		int right_max = findmax(root->right);
		if( root->data >= left_max && root->data >= right_max)
			return root->data;
		else if( left_max >= right_max)
			return left_max;
		else
			return right_max;
	}
}





int main() {
	
	treenode *root;
	createtree(&root, 50);
	// print(root);

	cout << "The maximum number of in this tree is " << findmax(root) << endl;
	return 0;
}
	
	
