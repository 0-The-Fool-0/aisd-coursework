#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 7000;

int dp[maxn][maxn];
char from[maxn][maxn];

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    string s;
    fin >> s;
    int n = static_cast<int>(s.size());

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = (i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0) + 2;
                from[i][j] = 0;
            }
            else {
                if (dp[i + 1][j] >= dp[i][j - 1]) {
                    dp[i][j] = dp[i + 1][j];
                    from[i][j] = 1;
                }
                else {
                    dp[i][j] = dp[i][j - 1];
                    from[i][j] = 2;
                }
            }
        }
    }
    char res_left[maxn + 1], res_right[maxn + 1];
    int l = 0, r = n - 1;
    int left_len = 0, right_len = 0;
    while (l <= r) {
        if (l == r) {
            res_left[left_len++] = s[l];
            break;
        }
        if (s[l] == s[r]) {
            res_left[left_len++] = s[l];
            res_right[right_len++] = s[r];
            ++l; --r;
        }
        else if (from[l][r] == 1) {
            ++l;
        }
        else {
            --r;
        }
    }

    string palindrome;
    palindrome.reserve(left_len + right_len);
    for (int i = 0; i < left_len; i++) palindrome += res_left[i];
    for (int i = right_len - 1; i >= 0; i--) palindrome += res_right[i];

    fout << dp[0][n - 1] << "\n" << palindrome << "\n";
    return 0;
}
