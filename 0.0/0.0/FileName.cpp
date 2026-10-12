#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
int main() {
    // Открытие входного и выходного файлов
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile || !outputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    // Подсчет количества чисел в файле
    long long size = 0;
    long long size2 = 0;
    int index=0;
    int temp;
    while (inputFile >> temp) {
        ++size;
    }

    // Проверка на пустой файл
    if (size == 0) {
        cerr << "Input file is empty." << endl;
        outputFile << "Input file is empty." << endl;
        inputFile.close();
        outputFile.close();
        return 1;
    }

    // Возврат в начало файла для чтения данных
    inputFile.clear();
    inputFile.seekg(0, ios::beg);

    // Создание динамического массива
    long* a = new long[size];
   
    for (long i = 0; i < size; ++i) {
        inputFile >> a[i];
    }
    inputFile.close();
	sort(a, a + size);
    long long sum = a[0];
    for (long i = 1; i < size; ++i) {
        if (a[i] != a[i - 1]) {
            sum += a[i];
        }
    }

    outputFile << sum << endl;
	outputFile.close();
    cout << sum << endl;
    return 0;
}
