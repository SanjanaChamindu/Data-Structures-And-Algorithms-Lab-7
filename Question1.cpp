#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root == NULL) return;
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *root, int key) {
    node *new_node = new node();
    new_node->key = key;

    if (root == NULL){
        root = new_node;
    }
    else if (root->key > key){
        root->left = insertNode(root->left, key);
    }
    else {
        root->right = insertNode(root->right, key);
    }
    return root;
}

struct node* minNode(struct node *node){
    if (node->left == NULL) return node;
    else return minNode(node->left);
};

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if (root==NULL) return root;
    else if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else{
        if (root->left==NULL and root->right==NULL){
            delete root;
            root = NULL;
            return root;
        }
        else if (root->left == NULL){
            root = root->right;
            return root;
        }
        else if (root->right == NULL){
            root = root->left;
            return root;
        }
        else{
            struct node* temp = minNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }

  traverseInOrder(root);
}
