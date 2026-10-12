#include <iostream>  
#include <fstream>  
#include <vector>  
#include <algorithm>  
#include <string> 
using namespace std;  

struct Node {  
   int key;  
   Node* left = nullptr;  
   Node* right = nullptr;  
   Node(int k) : key(k) {}  
};  

Node* findMin(Node* root) {  
   while (root && root->left) root = root->left;  
   return root;  
}  
Node* insert(Node* root, int key) {  
   if (!root) return new Node(key);  
   if (key < root->key) root->left = insert(root->left, key);  
   else root->right = insert(root->right, key);  
   return root;  
}  
Node* deleteRight(Node* root, int key) {  
   if (!root) return nullptr;  
   if (key < root->key)  
       root->left = deleteRight(root->left, key);  
   else if (key > root->key)  
       root->right = deleteRight(root->right, key);  
   else {  
       if (!root->left) {  
           Node* tmp = root->right;  
           delete root;  
           return tmp;  
       }  
       if (!root->right) {  
           Node* tmp = root->left;  
           delete root;  
           return tmp;  
       }  
       Node* mn = findMin(root->right);  
       root->key = mn->key;  
       root->right = deleteRight(root->right, mn->key);  
   }  
   return root;  
}  
void preorder_left(Node* root, ofstream& out) {
    if (!root) return;
    out << root->key << '\n';
    preorder_left(root->left, out);
    preorder_left(root->right, out);
}
int main() {  
   ifstream in("input.txt");  
   ofstream out("output.txt");  

   int delKey;  
   in >> delKey;  
   string empty;  
   getline(in, empty); // пропустить пустую строку  

   Node* root = nullptr;  
   int key;  
   while (in >> key) {  
       root = insert(root, key);  
   }  

   root = deleteRight(root, delKey);  

   preorder_left(root, out);

   return 0;  
}