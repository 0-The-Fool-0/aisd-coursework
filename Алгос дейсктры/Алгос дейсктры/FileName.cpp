#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

const long long INF = 1e18;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m;
    fin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        fin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    vector<long long> dist(n + 1, INF);
    dist[1] = 0;

    priority_queue<pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>> pq;

    pq.push({ 0, 1 });

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        long long d = top.first;
        int v = top.second;

        if (d > dist[v]) continue;
        if (v == n) break;

        for (size_t i = 0; i < adj[v].size(); ++i) {
            int to = adj[v][i].first;
            int w = adj[v][i].second;
            if (dist[to] > d + w) {
                dist[to] = d + w;
                pq.push({ dist[to], to });
            }
        }
    }

    fout << dist[n];
    return 0;
}
