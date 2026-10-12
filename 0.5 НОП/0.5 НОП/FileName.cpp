#include <iostream>
using namespace std;

const int maxn = 1000;

int dp[maxn + 1][maxn + 1];
int A[maxn], B[maxn];
int ai[maxn], bj[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n; ++i) cin >> B[i];

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            dp[i][j] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int len = 0;
    int i = n, j = n;
    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) {
            ai[len] = i - 1;
            bj[len] = j - 1;
            --i; --j; ++len;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1]) {
            --i;
        }
        else {
            --j;
        }
    }

    cout << len << endl;
    for (int k = len - 1; k >= 0; --k) {
        cout << ai[k] << (k > 0 ? " " : "\n");
    }
    for (int k = len - 1; k >= 0; --k) {
        cout << bj[k] << (k > 0 ? " " : "\n");
    }

    return 0;
}
