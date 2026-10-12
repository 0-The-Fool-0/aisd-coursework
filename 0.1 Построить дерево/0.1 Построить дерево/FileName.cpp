#include <fstream>
using namespace std;
struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

void insert(Node*& root, int key) {
    if (!root) {
        root = new Node(key);
        return;
    }
    if (key < root->key) {
        insert(root->left, key);
    }
    else if (key > root->key) {
        insert(root->right, key);
    }
}

void preorder_left(Node* root, ofstream& out) {
    if (!root) return;
    out << root->key << '\n';
    preorder_left(root->left, out);
    preorder_left(root->right, out);
}

void delete_tree(Node* root) {
    if (!root) return;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    Node* root = nullptr;
    int key;
    while (in >> key) {
        insert(root, key);
    }
    preorder_left(root, out);
    delete_tree(root);
    return 0;
}
