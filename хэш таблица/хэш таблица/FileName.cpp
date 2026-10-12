#include <fstream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int m, c, n;
    fin >> m >> c >> n;

    vector<int> table(m, -1);
    set<int> inserted;

    for (int k = 0; k < n; ++k) {
        int key;
        fin >> key;
        if (inserted.count(key)) continue;
        inserted.insert(key);

        for (int i = 0; i < m; ++i) {
            int idx = ((key % m) + c * i) % m;
            if (table[idx] == -1) {
                table[idx] = key;
                break;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        fout << table[i];
        if (i + 1 < m) fout << ' ';
    }
    fout << '\n';
    return 0;
}
