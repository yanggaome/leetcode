/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class node
{
    public:
        node(int val);
        ~node();
        int nodeVal;
        node* left;
        node* right;
};

node::node(int val): nodeVal(val), left(nullptr), right(nullptr)
{
    //nodeVal = val;
    //left = nullptr;
    //right = nullptr;
}

node::~node()
{
    cout << "calling destructor for node "<< nodeVal << endl;
}

// self, left, right
void preOrderTran(node* root, vector<int>& result)
{
    if (!root)
        return;
    cout << root->nodeVal << endl;
    
    result.push_back(root->nodeVal);
    
    preOrderTran(root->left, result);
    preOrderTran(root->right, result);
}

// left, self, right
void inOrderTran(node* root, vector<int>& result)
{
    if (!root)
        return;
    
    inOrderTran(root->left, result);
    
    cout << root->nodeVal << endl;
    result.push_back(root->nodeVal);
    
    inOrderTran(root->right, result);
}

// left, right, self
void postOrderTran(node* root, vector<int>& result)
{
    // base case
    if (!root)
        return;
    
    postOrderTran(root->left, result);
    postOrderTran(root->right, result);
    cout << root->nodeVal << endl;
    result.push_back(root->nodeVal);
}

int getHeight(node* root)
{
    if (!root)
        return 0;
    
    int leftChildHeight = getHeight(root->left);
    int rightChildHeight = getHeight(root->right);
    return 1 + std::max(leftChildHeight, rightChildHeight);
}

int main ()
{
    //      10
    //  5       15
    //2   7  12   20
    node* root = new node(10);
    root->left = new node(5);
    root->right = new node(15);
    root->left->left = new node(2);
    root->left->right = new node(7);
    root->right->left = new node(12);
    root->right->right = new node(20);
    
    vector<int> result;
    //preOrderTran(root, result);
    //inOrderTran(root, result);
    postOrderTran(root, result);
    //for (auto x:result)
    //    cout << x << endl;
    cout << "tree height is " << getHeight(root) << endl;
    
    return 0;
}
