#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x : a) std::cin >> x;

    std::vector<int> dp(n, -1);      // максимальное число комаров на i-й кувшинке
    std::vector<int> prev(n, -1);    // откуда пришли на i-ю кувшинку

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

    if (dp[n-1] == -1) {
        std::cout << -1 << std::endl;
        return 0;
    }

    // Восстановим путь
    std::vector<int> path;
    for (int i = n-1; i != -1; i = prev[i])
        path.push_back(i + 1); // индексация с 1
    std::reverse(path.begin(), path.end());

    std::cout << dp[n-1] << std::endl;
    for (size_t i = 0; i < path.size(); ++i) {
        if (i) std::cout << " ";
        std::cout << path[i];
    }
    std::cout << std::endl;
    return 0;
}
