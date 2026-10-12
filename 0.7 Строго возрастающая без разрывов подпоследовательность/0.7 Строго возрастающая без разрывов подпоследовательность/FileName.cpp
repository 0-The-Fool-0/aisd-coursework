#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        fin >> a[i];
    }

    vector<int> lis;
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(lis.begin(), lis.end(), a[i]);
        if (it == lis.end()) {
            lis.push_back(a[i]);
        }
        else if (*it > a[i]) {
            *it = a[i];
        }
    }

    fout << lis.size() << endl;
    return 0;
}
