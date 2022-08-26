#include<iostream>
using namespace std;

struct Node{
   int data;
   struct Node* left, *right;
};

Node* newNode(int data){
    Node* temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void printPostorder(struct Node* node){
    if(node == NULL){
        return;
    }
    else{
        printPostorder(node->left);
        printPostorder(node->right);
        cout << node->data << " ";
    }
}

void printInorder(struct Node* node){
    if(node == NULL){
       return;
    }
    else{
        printInorder(node->left);
        cout << node->data << " ";
        printInorder(node->right);
    }
}

void printPreorder(struct Node* node){
    if(node == NULL){
        return;
    }
    else{

        cout << node->data << " ";
        printPreorder(node->left);
        printPreorder(node->right);
    }
}



int main(){
    
 struct Node* root = newNode(1);
 root->left = newNode(10);
 root->right = newNode(20);
 root->left->left = newNode(30);
 root->left->left->left = newNode(40);
 root->left->left->right = newNode(50);

cout << endl << "Binary tree preorder traversal " << endl;
printPreorder(root);

cout << endl << "Binary tree inorder traversal " << endl;
printInorder(root);

cout << endl << "Binary tree postorder traversal " << endl;
printPostorder(root);

    return 0;
}