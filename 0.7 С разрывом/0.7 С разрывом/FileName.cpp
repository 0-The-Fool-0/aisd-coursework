#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n;
    fin >> n;
    std::vector<int> a(n);
    for (int& x : a) fin >> x;

    // LIS слева для каждой позиции
    std::vector<int> lis_left(n), lis_right(n);
    std::vector<int> dp;

    for (int i = 0; i < n; ++i) {
        auto it = std::lower_bound(dp.begin(), dp.end(), a[i]);
        if (it == dp.end()) dp.push_back(a[i]);
        else *it = a[i];
        lis_left[i] = dp.size();
    }

    dp.clear();
    for (int i = n - 1; i >= 0; --i) {
        auto it = std::lower_bound(dp.begin(), dp.end(), -a[i]);
        if (it == dp.end()) dp.push_back(-a[i]);
        else *it = -a[i];
        lis_right[i] = dp.size();
    }

    int result = 0;
    // Без разрыва
    for (int i = 0; i < n; ++i)
        result = std::max(result, lis_left[i]);
    // С одним разрывом
    for (int i = 0; i + 1 < n; ++i)
        result = std::max(result, lis_left[i] + lis_right[i + 1]);

    fout << result << "\n";
    return 0;
}
