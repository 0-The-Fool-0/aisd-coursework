#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
struct result {
    int b; // 1 - найден, 0 - не найден
    long l;    // Индекс первого элемента > = x
    long r;    // Индекс первого элемента > x
};


result binarysearch(long* arr, long n, long x) {
    int b = 0;
    // Поиск l: первого элемента >= x
    long left = 0, right = n;
    while (left < right) {
        long mid = left + (right - left) / 2;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid;
    }
    long l = left;

    // Поиск r: первого элемента > x
    right = n;
    while (left < right) {
        long mid = left + (right - left) / 2;
        if (arr[mid] <= x)
            left = mid + 1;
        else
            right = mid;
    }
    long r = left;
    if (arr[l] == x) {
        b = 1;
    }
    return { b, l, r };
}

int main() {
    long size_a, size_b;
    cin >> size_a;
    long* a = new long[size_a];
    for (long i = 0; i < size_a; ++i) {
        cin >> a[i];
    }
    cin >> size_b;
    long* b = new long[size_b];
    for (long i = 0; i < size_b; ++i) {
        cin >> b[i];
    }
    for (long i = 0; i < size_b; ++i) {
        result result = binarysearch(a, size_a, b[i]);
        cout << result.b << " " << result.l << " " << result.r << endl;
    }
    delete[] a;
    delete[] b;
    return 0;
}
 