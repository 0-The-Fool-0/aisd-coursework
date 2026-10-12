#include <fstream>
#include <vector>
#include <limits>
using namespace std;

struct Node {
    int value;
    int left = -1;
    int right = -1;
    long long minVal = LLONG_MIN;
    long long maxVal = LLONG_MAX;
};

void fillIntervals(vector<Node>& tree, int root, long long minVal, long long maxVal) {
    tree[root].minVal = minVal;
    tree[root].maxVal = maxVal;
    for (size_t i = 1; i < tree.size(); ++i) {
        int parent = -1;
        char direction = ' ';
        for (size_t j = 0; j < tree.size(); ++j) {
            if (tree[j].left == i) { parent = j; direction = 'L'; break; }
            if (tree[j].right == i) { parent = j; direction = 'R'; break; }
        }
        if (parent == -1) continue;
        if (direction == 'L') {
            tree[i].minVal = tree[parent].minVal;
            tree[i].maxVal = (long long)tree[parent].value - 1;
        }
        else if (direction == 'R') {
            tree[i].minVal = (long long)tree[parent].value;
            tree[i].maxVal = tree[parent].maxVal;
        }
    }
}



bool isBST(const vector<Node>& tree) {
    for (const Node& node : tree) {
        if (node.value < node.minVal || node.value > node.maxVal)
            return false;
    }
    return true;
}

int main() {
    ifstream in("bst.in");
    ofstream out("bst.out");
    int n;
    in >> n;
    if (n == 0) {
        out << "YES\n";
        return 0;
    }
    vector<Node> tree(n);
    in >> tree[0].value;
    for (int i = 1; i < n; ++i) {
        int m, p;
        char c;
        in >> m >> p >> c;
        tree[i].value = m;
        if (c == 'L') {
            tree[p - 1].left = i;
        }
        else {
            tree[p - 1].right = i;
        }
    }
    fillIntervals(tree, 0, LLONG_MIN, LLONG_MAX);
    bool result = isBST(tree);
    out << (result ? "YES" : "NO") << endl;
    return 0;
}
