#include <iostream>
using namespace std;

const int MOD = 1000000007;

long long mod_pow(long long a, long long b, int mod) {
    long long t = 1;
    while (b > 0) {
        if (b & 1) t = t * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return t;
}

long long comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k > n - k) {
        k = n - k;
    }
    long long num = 1, dnum = 1;
    for (int i = 1; i <= k; ++i) {
        num = num * (n - i + 1) % MOD;
        dnum = dnum * i % MOD;
    }
    return num * mod_pow(dnum, MOD - 2, MOD) % MOD;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << comb(n, k) << endl;
    return 0;
}
