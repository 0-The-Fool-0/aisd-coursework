#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int key;
    Node* left = nullptr;
    Node* right = nullptr;
    int depth = -1;      
    int semipath = 0;    
    Node(int k) : key(k) {}
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
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
int computeDepthAndSemipath(Node* node, int& maxSemi, vector<Node*>& maxNodes) {
    if (!node) return -1;
    int dl = computeDepthAndSemipath(node->left, maxSemi, maxNodes);
    int dr = computeDepthAndSemipath(node->right, maxSemi, maxNodes);
    node->depth = 1 + max(dl, dr);
    int leftDist = (node->left ? 1 + dl : 0);
    int rightDist = (node->right ? 1 + dr : 0);
    node->semipath = leftDist + rightDist;
    if (node->semipath > maxSemi) {
        maxSemi = node->semipath;
        maxNodes.clear();
        maxNodes.push_back(node);
    }
    else if (node->semipath == maxSemi) {
        maxNodes.push_back(node);
    }
    return node->depth;
}

void collectDeepestPath(Node* node, bool goLeft, std::vector<int>& result) {
    Node* cur = goLeft ? node->left : node->right;
    while (cur) {
        if (find(result.begin(), result.end(), cur->key) == result.end())
            result.push_back(cur->key);
        int dl = cur->left ? cur->left->depth : -1;
        int dr = cur->right ? cur->right->depth : -1;
        if (dl >= dr) cur = cur->left;
        else cur = cur->right;
    }
}

void preorder(Node* root, vector<int>& out) {
    if (!root) return;
    out.push_back(root->key);
    preorder(root->left, out);
    preorder(root->right, out);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("in.txt");
    ofstream fout("out.txt");
    vector<int> keys;
    int v;
    while (fin >> v) keys.push_back(v);

    Node* root = nullptr;
    for (int k : keys) root = insert(root, k);

    int maxSemi = 0;
    vector<Node*> maxNodes;
    computeDepthAndSemipath(root, maxSemi, maxNodes);

    vector<int> verticesOnMaxPaths;
    for (Node* node : maxNodes) {
        if (find(verticesOnMaxPaths.begin(), verticesOnMaxPaths.end(), node->key) == verticesOnMaxPaths.end())
            verticesOnMaxPaths.push_back(node->key);
        if (node->left) collectDeepestPath(node, true, verticesOnMaxPaths);
        if (node->right) collectDeepestPath(node, false, verticesOnMaxPaths);
    }

    vector<int> sortedVerts = verticesOnMaxPaths;
    sort(sortedVerts.begin(), sortedVerts.end());
    int keyToDelete = sortedVerts[1];

    root = deleteRight(root, keyToDelete);

    vector<int> out;
    preorder(root, out);
    for (int x : out) fout << x << "\n";

    return 0;
}

