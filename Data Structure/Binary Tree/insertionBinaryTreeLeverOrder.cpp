#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data){
    Node* newNode = new Node();

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node* insertNode(Node* root, int data){
    if(root == NULL){
        root = createNode(data);
        return root;
    }

    else{
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){

            Node* temp = q.front();
            q.pop();

            if(temp->left != NULL){
                q.push(temp->left);
            }
            else{
                temp->left = createNode(data);
                return root;
            }

            if(temp->right != NULL){
                q.push(temp->right);

            }
            else{
                temp->right = createNode(data);
                return root;
            }
        }
    }
}

void inorderTraversal(Node* node){
    if(node == NULL){
        return;
    }

    else{
        
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }
}

int main(){

    Node* root = createNode(10);
    root->left = createNode(11);
    root->left->left = createNode(7);
    root->right = createNode(9);
    root->right->left = createNode(15);
    root->right->right = createNode(8);

    cout << "Inorder traversal before insertion : " << endl;
    inorderTraversal(root);
    cout << endl;

    int key = 50;
    root = insertNode(root, key);

    cout << "Inorder traversal after insertion : " << endl;
    inorderTraversal(root);
    cout << endl;

    return 0;
}