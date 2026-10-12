#include <fstream>
#include <limits>
using namespace std;
int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int s;
    fin >> s;
    int p[101];
    for (int i = 0; i < s; ++i) {
        int n, m;
        fin >> n >> m;
        p[i] = n;
        if (i == s - 1) p[s] = m;
    }

    int dp[100][100] = {};
    for (int len = 2; len <= s; ++len) {
        for (int i = 0; i + len <= s; ++i) {
            int j = i + len - 1;
            dp[i][j] = numeric_limits<int>::max();
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (cost < dp[i][j]) dp[i][j] = cost;
            }
        }
    }

    fout << dp[0][s - 1] << '\n';
    return 0;
}
