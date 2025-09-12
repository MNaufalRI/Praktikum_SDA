#include <iostream>
using namespace std;

void MembalikArray(int *arr, int n) {
    int *awal = arr;
    int *akhir = arr + n - 1;
    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
}

bool Bil_Prima(int x) {
    if (x < 2) {
        return false;
    }

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    const int data = 7;
    int arr[data];
    int angka = 2, indeks = 0;

    while (indeks < data) {
        if (Bil_Prima(angka)) {
            arr[indeks++] = angka;
        }
        angka++;
    }

    cout << "Array sebelum dibalik: ";
    for (int i = 0; i < data; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    MembalikArray(arr, data);

    cout << "Array sesudah dibalik: ";
    for (int i = 0; i < data; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}