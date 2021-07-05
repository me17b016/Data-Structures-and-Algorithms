#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node (int data) {
        val = data;
        left = NULL;
        right = NULL;
    }    
};

void preOrderT(Node* root) {
    if (root == NULL) return;
    cout << root -> val << ' ';
    preOrderT(root -> left);
    preOrderT(root -> right);    
} 

void inOrderT(Node* root) {
    if (root == NULL) return;
    inOrderT(root -> left);
    cout << root -> val << ' ';
    inOrderT(root -> right);    
}

void postOrderT(Node* root) {
    if (root == NULL) return;
    postOrderT(root -> left);
    postOrderT(root -> right);
    cout << root -> val << ' ';
}

void preOrder(Node* root) {
    stack<Node*> S;
    S.push(root);
    
    while (!S.empty()) {
        Node* curr = S.top();
        S.pop();
        cout << curr -> val << ' ';
        
        
        if (curr -> right != NULL) S.push(curr -> right);
        if (curr -> left != NULL) S.push(curr -> left);
    }    
}

void inOrder(Node* root) {
    stack<Node*> S;
    
    Node* curr = root;
    
    while (curr != NULL || !S.empty()) {

        while (curr != NULL) {
            S.push(curr);
            curr = curr -> left;
        }
        curr = S.top();
        S.pop();
        cout << curr -> val << ' ';
        curr = curr -> right;
    }
}

void postOrder(Node* root) {
     stack<Node*> S;
     Node* pre = NULL;
     Node* curr = root;
     
     while (curr != NULL || !S.empty()) {
         if (curr != NULL) {
             S.push(curr);
             curr = curr -> left;
         }
         else {
             curr = S.top();
             if (curr -> right == NULL || curr -> right == pre) {
                 cout << curr -> val << ' ';
                 S.pop();
                 pre = curr;
                 curr = NULL;
             }
             else {
                 curr = curr -> right;
             }
         }
     }   
}

int main() {
    Node* root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    
    preOrderT(root);cout << '\n';
    inOrderT(root);cout << '\n';
    postOrderT(root); cout << '\n';
    preOrder(root); cout << '\n';
    inOrder(root); cout << '\n';
    postOrder(root);
}
