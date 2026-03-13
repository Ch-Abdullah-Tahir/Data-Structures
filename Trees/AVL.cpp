#include<iostream>
#include<queue>
using namespace std;
struct node 
{
	int data;
	node* left;
	node* right;
	int height;
public:
	//node() :left(nullptr), right(nullptr) {}
	node(int d) :data(d), left(nullptr), right(nullptr),height(1)
	{

	}
};
class Tree
{
	node* root;
public:
	Tree() :root(nullptr) {}
	int getheight(node * r)
	{
		if (r == nullptr)
		{
			return 0;
		}
		else {
			return r->height;
		}
	}
	int getBalance(node* r)
	 {
		return getheight(r->left) - getheight(r->right);
	}
	node* rightRotation(node * r)
	{
		node* child = r->left;
		r->left = child->right;
		child->right = r;	
		//Update heights of root and child respectively,the order is important,don't care how it is done
		r->height = 1 + max(getheight(r->left), getheight(r->right));
		child->height = 1 + max(getheight(child->left), getheight(child->right));
		return child;
	}
	node* leftRotation(node* r)
	{
		node* child = r->right;
		r->right = child->left;
		child->left = r;
		//Update heights of root and child respectively,the order is important
		r->height = 1 + max(getheight(r->left), getheight(r->right));
		child->height = 1 + max(getheight(child->left), getheight(child->right));
		return child;

	}
	node* createTree(node*& r, int key)
	{
		node* temp = new node(key);
		if (r == nullptr)
		{
			r = temp;
			return r;
		}
		else if (key > r->data)//note it was >= in BST
		{
				r->right = createTree(r->right, key);
		}
		else if(key <r->data)
		{
				r->left = createTree(r->left, key);
		}
		else
		{
			return r;//duplicates not allowed in AVLS
		}
		//update height
		r->height = 1 + max(getheight(r->left), getheight(r->right));
		int balance = getBalance(r);
		//LL CASE
		if (balance > 1 && key < r->left->data) 
		{
			return rightRotation(r);
		}
		//RR CASE
		else if (balance<-1 && key>r->right->data)
		{
			return leftRotation(r);
		}
		//LR CASE
		else if (balance > 1 && key > r->left->data)
		{
			r->left=leftRotation(r->left);//on 2,3
			return rightRotation(r);//on 1,2
		}
		//RL CASE
		else if (balance<-1 && key<r->right->data)
		{
			r->right=rightRotation(r->right);//on 2,3
			return leftRotation(r);//on 1,2	
		}
		//NO UNBALANCE SHIT
		else
		{
			return r;
		}
	}
	void insert(int x)
	{
	root=createTree(root, x);
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
	node* deleteNode(node* root, int key) {
		if (!root) {
			return nullptr;
		}
		if (key > root->data) 
		{
			deleteNode(root->right, key);
		}
		else if (key <root->data)
		{
			deleteNode(root->left, key);
		}
		else
		{
			//Leaf node 
			if (root->left == nullptr && root->right == nullptr)
			{
				delete root;
				return nullptr;
			}
			//one child
			else if (root->right == nullptr && root->left != nullptr) 
			{
				node* temp = root->left;
				delete root;
				return temp;
			}
			else if (root->right != nullptr && root->left == nullptr)
			{
				node* temp = root->right;
				delete root;
				return temp;
			}
			else 
			{
				node* child = root->right;
				while (child->left)
				{
					child = child->left;
				}
				  //yha wo fikar ni ke uska bhi koi child ho kiu ke huwa b tou delete call krna wo handle krle ga]
				root->data = child->data;
				root->right = deleteNode(root->right, child->data);


			}

		}
		root->height = 1+max(getheight(root->left), getheight(root->right));
		//check balance
		int balance = getBalance(root);
		if (balance > 1)
		{
			//LL
			if (getBalance(root->left) >= 0)
			{
				//LL so right
				return rightRotation(root);
			}
			//LR
			else {
				root->left = leftRotation(root->left);
				return rightRotation(root);
			}
		}
		else if (balance < -1)
		{

			if (getBalance(root->right) <= 0)
			{
				//RR so left
				return leftRotation(root);
			}
			else {
				//RL
				root->right = rightRotation(root->right);
				return leftRotation(root);
			}
		}
		else {
			return root;
		}
	}






};
int main() 
{
	Tree t;
	t.insert(10);
	t.insert(20);
	t.insert(30);
	t.insert(25);
	t.insert(28);
	t.insert(27);
	t.insert(5);

	t.display();  // sorted 
}
