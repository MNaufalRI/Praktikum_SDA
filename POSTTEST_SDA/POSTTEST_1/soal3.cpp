#include <iostream>
#include <string>
#include <iomanip> // Digunakan untuk membuat tabel agar lebih rapi
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int main() {
    const int jumlah = 4;
    Mahasiswa mahasiswa[jumlah];

    cout << "Input data mahasiswa:" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << "\nMahasiswa ke-" << i+1 << endl;
        cout << "Nama: "; cin >> mahasiswa[i].nama;
        cout << "NIM : "; cin >> mahasiswa[i].nim;
        while (true){
            cout << "IPK : "; 
            cin >> mahasiswa[i].ipk;
            if (mahasiswa[i].ipk < 0.0 || mahasiswa[i].ipk > 4.0) {
                cout << "IPK hanya bisa diisi dari angka 0.0 hingga 4.0!\n";
            }
            else {
                break;
            }

        }
    }

    for (int i = 0; i < jumlah-1; i++) {
        for (int j = i+1; j < jumlah; j++) {
            if (mahasiswa[i].ipk > mahasiswa[j].ipk) {
                Mahasiswa temp = mahasiswa[i];
                mahasiswa[i] = mahasiswa[j];
                mahasiswa[j] = temp;
            }
        }
    }

    cout << "\nData mahasiswa setelah diurutkan (IPK ascending):\n";

    cout << left << setw(20) << "Nama"
        << setw(15) << "NIM"
        << setw(10) << "IPK" << endl;

    cout << string(45, '-') << endl;

    for (int i = 0; i < jumlah; i++) {
        cout << left << setw(20) << mahasiswa[i].nama
            << setw(15) << mahasiswa[i].nim
            << setw(10) << fixed << setprecision(2) << mahasiswa[i].ipk
            << endl;
    }

    return 0;
}


