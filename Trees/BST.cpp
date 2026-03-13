#include<iostream>
#include<queue>
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
public:
	node():left(nullptr),right(nullptr){}
	node(int d):data(d),left(nullptr),right(nullptr) 
	{
	}
};
class Tree
{
	node* root;
public:
	Tree():root(nullptr){}
node* createTree(node*& r,int x)
{
		node* temp = new node(x);
		if (r == nullptr)
		{
			r = temp;
			return r;
		}
		else 
		{
			if (x >= r->data)
			{
				r->right=createTree(r->right,x);
			}
			else
			{
				r->left=createTree(r->left, x);
			}
		}
		//return r;//function should return a node
}
void insert(int x) 
{
	createTree(root, x);
}
void inorder(node* root) 
{
	if (root == nullptr) return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void display() 
{
	inorder(root);
	cout << endl;
}
};
node* deleteNode(node* root,int target)
{
	if (root->data > target)
	{
		root->left = deleteNode(root->left, target);
		return root;
	}
	else if (root->data < target)
	{
		root->right = deleteNode(root->right, target);
		return root;
	}
	else {
		//no child 
		if (root->left == nullptr&&root->right==nullptr) 
		{
			delete root;
			return nullptr;
		}
		//only right child exists
		else if (root->left == nullptr)
		{
			node* temp = root->right;
			delete root;
			return temp;
		}
		//only left exists
		else if (root->right == nullptr)
		{
			node* temp = root->left;
			delete root;
			return temp;
		}
		else {
			//find replacement
			node* child = root->left;
			node* parent = root;
			while (child->right) {
				parent = child;
				child = child->right;
			}
			if (root != parent) {
				parent->right = child->left;
				child->left = root->left;
				child->right = root->right;
				delete root;
				return child;
			}
			else {
				child->right = root->right;
				delete root;
				return child;
			}

		}
	}
}
int main() 
{
	Tree tree;
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);
	tree.insert(3);
	tree.insert(7);
	cout << "Inorder traversal (sorted): ";
	tree.display();
}