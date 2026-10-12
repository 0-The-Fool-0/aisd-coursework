#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int R, C;
    if (!fin) return 0;
    fin >> R >> C;

    vector<pair<int, int>> col(C);
    vector<vector<int>> adj(R + 1);
    vector<int> deg(R + 1, 0);

    for (int i = 0; i < C; ++i) {
        int u, v;
        fin >> u >> v;
        col[i] = { u, v };
        adj[u].push_back(i);
        adj[v].push_back(i);
        deg[u]++; deg[v]++;
    }
    if (C < R) { fout << "No"; return 0; }
    for (int r = 1; r <= R; ++r) {
        if (deg[r] == 0) { fout << "No"; return 0; }
    }
    vector<int> match_col(C, -1);
    vector<int> match_row(R + 1, -1);

    vector<char> used(R + 1, 0);
    function<bool(int)> dfs = [&](int r) -> bool {
        if (used[r]) return false;
        used[r] = 1;
        for (int j : adj[r]) {
            if (match_col[j] == -1) {
                match_col[j] = r;
                match_row[r] = j;
                return true;
            }
        }
        for (int j : adj[r]) {
            int r2 = match_col[j];
            if (r2 != -1 && !used[r2]) {
                if (dfs(r2)) {
                    match_col[j] = r;
                    match_row[r] = j;
                    return true;
                }
            }
        }
        return false;
        };

    for (int r = 1; r <= R; ++r) {
        fill(used.begin(), used.end(), 0);
        dfs(r);
    }

    for (int r = 1; r <= R; ++r) {
        if (match_row[r] == -1) {
            fout << "No";
            return 0;
        }
    }
    vector<int> ans(C, -1);
    for (int r = 1; r <= R; ++r) {
        int j = match_row[r];
        if (j != -1) ans[j] = r;
    }
    for (int j = 0; j < C; ++j) {
        if (ans[j] == -1) {
            
            ans[j] = col[j].first;
        }
    }

    for (int j = 0; j < C; ++j) {
        fout << ans[j] << (j + 1 < C ? ' ' : '\n');
    }
    return 0;
}
