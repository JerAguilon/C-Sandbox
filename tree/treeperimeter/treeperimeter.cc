#include<iostream>
#include<stack>

using namespace std;

struct node {
    int val;
    node *left;
    node *right;

    node() {
        left = NULL;
        right = NULL;
        val = -1;
    }
};

class Tree {
    public:
        node* root;
        Tree() {
            root = NULL;
        }
        void printPerimeter();
};

void Tree::printPerimeter() {
    stack<node*> stack{};
    
    node* curr = root;
    while (curr != NULL && curr->left != NULL) {
        cout << curr->val << "\n";
        curr = curr->left;
    }

    stack.push(root);
    while (!stack.empty()) {
        node* curr = stack.top();
        if (curr->left == NULL && curr->right == NULL) {
            cout << curr->val<<"\n";
        }
        stack.pop();
        if (curr->right != NULL) stack.push(curr->right);
        if (curr->left != NULL) stack.push(curr->left);
    }

    curr = root->right;
    while (curr != NULL && curr->right != NULL) {
        stack.push(curr);
        curr = curr->right;
    }
    while(!stack.empty()) {
        cout << stack.top()->val << "\n";
        stack.pop();
    }
}

int main() {
    Tree tree{}; 

    node* root = new node;
    node* root_l = new node;
    node* root_r = new node;

    node* root_ll = new node;
    node* root_lr = new node;

    node* root_rr = new node;

    root->val = 0;
    root_l->val = 1;
    root_r->val = 5;
    root_ll->val = 2;
    root_lr->val = 3;
    root_rr->val = 4;

    root->left = root_l;
    root->right = root_r;
    root_l->left = root_ll;
    root_l->right = root_lr;
    root_r->right = root_rr;
    tree.root = root;
    tree.printPerimeter();
}
