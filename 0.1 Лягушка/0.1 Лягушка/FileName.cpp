#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; ++i) cin >> a[i];

    int* dp = new int[n];
    int* prev = new int[n];
    for (int i = 0; i < n; ++i) {
        dp[i] = -1;
        prev[i] = -1;
    }

    dp[0] = a[0];

    for (int i = 0; i < n; ++i) {
        if (dp[i] == -1) continue;
        for (int jump = 2; jump <= 3; ++jump) {
            int j = i + jump;
            if (j < n) {
                if (dp[j] < dp[i] + a[j]) {
                    dp[j] = dp[i] + a[j];
                    prev[j] = i;
                }
            }
        }
    }

    if (dp[n - 1] == -1) {
        cout << -1 << endl;
        delete[] a;
        delete[] dp;
        delete[] prev;
        return 0;
    }

    int* path = new int[n];
    int path_len = 0;
    for (int i = n - 1; i != -1; i = prev[i])
        path[path_len++] = i + 1; 
  
    for (int i = 0; i < path_len / 2; ++i)
        swap(path[i], path[path_len - 1 - i]);

    cout << dp[n - 1] << endl;
    for (int i = 0; i < path_len; ++i) {
        if (i) cout << " ";
        cout << path[i];
    }
    cout << endl;

    delete[] a;
    delete[] dp;
    delete[] prev;
    delete[] path;
    return 0;
}