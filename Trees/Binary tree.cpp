//#include<iostream>
//#include<queue>
//using namespace std;
//
//struct node
//{
//    int data;
//    node* left;
//    node* right;
//
//    node(int d) : data(d), left(nullptr), right(nullptr) {}
//};
//
//int main()
//{
//    int x;
//    cout << "Enter the root element: ";
//    cin >> x;
//
//    node* root = new node(x); // create root node
//
//    queue<node*> q;
//    q.push(root); // push root so loop can start
//
//    int first, second;
//
//    while (!q.empty()) {
//        node* temp = q.front();
//        q.pop();
//
//        cout << "Enter the left node value for " << temp->data << " (-1 for no node): ";
//        cin >> first;
//        if (first != -1) {
//            temp->left = new node(first);
//            q.push(temp->left);
//        }
//
//        cout << "Enter the right node value for " << temp->data << " (-1 for no node): ";
//        cin >> second;
//        if (second != -1) {
//            temp->right = new node(second);
//            q.push(temp->right);
//        }
//    }
//
//    cout << "\nTree created successfully \n";
//    return 0;
//}
