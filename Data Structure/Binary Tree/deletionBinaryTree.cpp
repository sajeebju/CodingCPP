#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data){
    struct Node* temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
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

void deleteDeepest(struct Node* root, struct Node* d_node){
    queue<struct Node*> q;
    q.push(root);

    while(!q.empty()){
        
        Node* temp = q.front();
        q.pop();

        if(temp = d_node){
            temp = NULL;
            delete(d_node);
            return;
        }

        if(temp->right){
            if(temp->right == d_node){
                temp->right = NULL;
                delete(d_node);
                return;
            }
            else{
                q.push(temp->right);
            }
        }

        if(temp->left){
            if(temp->left == d_node){
                temp->left = NULL;
                delete(d_node);
                return;
            }
            else{
                q.push(temp->left);
            }
        }
    }
}

Node* deletion(struct Node* root, int data){
    if(root == NULL){
        return NULL;
    }

    if(root->left == NULL && root->right == NULL){
        if(root->data == data){
            return NULL;
        }
        else{
            return root;
        }
    }
    
    queue<struct Node*> q;
    q.push(root);

    struct Node* temp;
    struct Node* dataNode = NULL;

    while(!q.empty()){
          temp = q.front();
          q.pop();

          if(temp->data == data){
            dataNode = temp;
          }

          if(temp->left){
            q.push(temp->left);
          }

          if(temp->right){
            q.push(temp->right);
          }
        }

          if(dataNode != NULL){
            int x = temp->data;
            deleteDeepest(root, temp);
            dataNode->data = x;
    }
          return root;
    }

int main(){

    struct Node* root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->left->right = newNode(12);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);

    cout << "Inorder traversal before deletion : ";
    inorderTraversal(root);
 
    int key = 11;
    root = deletion(root, key);
 
    cout << endl;
    cout << "Inorder traversal after deletion : ";
    inorderTraversal(root);

    return 0;
}