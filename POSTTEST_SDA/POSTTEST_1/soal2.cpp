#include <iostream>
using namespace std;

int main() {
    const int ukuran = 3;
    int matriks[ukuran][ukuran] = {
        {5, 2, 3},
        {3, 6, 9},
        {2, 5, 4}
    };

    cout << "Matriks 3x3:" << endl;
    for (int i = 0; i < ukuran; i++) {
        for (int j = 0; j < ukuran; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    int jumlah = 0;
    for (int j = 0; j < ukuran; j++) {
        jumlah += matriks[1][j];
    }

    cout << "Jumlah elemen baris genap (baris ke-2) = " << jumlah << endl;

    return 0;
}
