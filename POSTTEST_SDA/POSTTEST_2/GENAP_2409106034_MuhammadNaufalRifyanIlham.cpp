#include <iostream>
#include <string>
#include <iomanip> // untuk memperindah output tabel
using namespace std;

struct Jadwal {
    string kodePenerbangan;
    string tujuan;
    string status;
};

struct Node {
    Jadwal data;
    Node* next;
};

Node* head = nullptr;
int urutanKode = 0;
string kodeDasar = "JT-034"; // sesuai NIM 034

string membuatKode() {
    if (urutanKode == 0) {
        urutanKode++;
        return kodeDasar; 
    } 

    else {
        return kodeDasar + "-" + to_string(urutanKode++);
    }
}

void tambahJadwal() {
    Node* baru = new Node;
    baru->data.kodePenerbangan = membuatKode();
    cout << "Masukkan tujuan penerbangan: ";
    cin.ignore();
    getline(cin, baru->data.tujuan);
    baru->data.status = "Tepat Waktu";
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }

    cout << "Jadwal berhasil ditambahkan dengan kode: "
         << baru->data.kodePenerbangan << endl;
}

void sisipJadwal() {
    int posisi = 5;
    Node* baru = new Node;
    baru->data.kodePenerbangan = membuatKode();
    cout << "Masukkan tujuan penerbangan: ";
    cin.ignore();
    getline(cin, baru->data.tujuan);
    baru->data.status = "Tepat Waktu";
    baru->next = nullptr;

    if (posisi == 1 || head == nullptr) {
        baru->next = head;
        head = baru;
        return;
    }

    Node* temp = head;
    int count = 1;
    while (temp->next != nullptr && count < posisi - 1) {
        temp = temp->next;
        count++;
    }

    baru->next = temp->next;
    temp->next = baru;
    cout << "Jadwal berhasil disisipkan di posisi ke-" << posisi << endl;
}

void hapusAwal() {
    if (head == nullptr) {
        cout << "Tidak ada jadwal untuk dihapus.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    cout << "Jadwal dengan kode " << temp->data.kodePenerbangan << " dihapus.\n";
    delete temp;
}

void updateStatus() {
    if (head == nullptr) {
        cout << "Tidak ada jadwal.\n";
        return;
    }

    string kode;
    cout << "Masukkan kode penerbangan yang ingin diupdate: ";
    cin >> kode;

    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.kodePenerbangan == kode) {
            cout << "Status saat ini: " << temp->data.status << endl;
            cout << "Pilih status baru:\n";
            cout << "1. Tepat Waktu\n2. Tertunda\n3. Dibatalkan\n\nPilihan : ";
            int pilihStatus;
            cin >> pilihStatus;

            if (pilihStatus == 1) {
                temp->data.status = "Tepat Waktu";
            } 
            else if (pilihStatus == 2) {
                temp->data.status = "Tertunda";
            } 
            else if (pilihStatus == 3) {
                temp->data.status = "Dibatalkan";
            } 
            else {
                cout << "Pilihan tidak valid. Status tidak diubah.\n";
                return;
            }

            cout << "Status penerbangan berhasil diperbarui menjadi: "
                 << temp->data.status << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Kode penerbangan tidak ditemukan.\n";
}

void tampilkanJadwal() {
    if (head == nullptr) {
        cout << "Tidak ada jadwal.\n";
        return;
    }

    Node* temp = head;
    cout << "^--------------+---------------------+------------------^\n";
    cout << "| " << left << setw(13) << "Kode"
         << "| " << setw(20) << "Tujuan"
         << "| " << setw(17) << "Status" << "|\n";
    cout << "+--------------+---------------------+------------------+\n";

    while (temp != nullptr) {
        cout << "| " << left << setw(13) << temp->data.kodePenerbangan
             << "| " << setw(20) << temp->data.tujuan
             << "| " << setw(17) << temp->data.status << "|\n";
        temp = temp->next;
    }
    cout << "+--------------+---------------------+------------------+\n";
}

int main() {
    string nama, nim;
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan NIM: ";
    getline(cin, nim);

    int pilihan;
    int totalGaris = 60;

    do {
        cout << "\n+" << string(totalGaris, '-') << "+\n";

        string judul = "FLIGHT SCHEDULE SYSTEM";
        int padding = (totalGaris - judul.length()) / 2;
        cout << "| "
             << setw(padding + judul.length()) << right << judul
             << setw(totalGaris - padding - judul.length()) << " "
             << "|\n";

        string header = "< " + nama + " - " + nim + " >";
        padding = (totalGaris - header.length()) / 2;
        cout << "| "
             << setw(padding + header.length()) << right << header
             << setw(totalGaris - padding - header.length()) << " "
             << "|\n";

        cout << "^" << string(totalGaris + 1, '-') << "^\n";
        cout << "| " << left << setw(totalGaris-1) << "1. Tambah Jadwal Penerbangan" << " |\n";
        cout << "| " << left << setw(totalGaris-1) << "2. Sisipkan Jadwal Penerbangan" << " |\n";
        cout << "| " << left << setw(totalGaris-1) << "3. Hapus Jadwal Paling Awal" << " |\n";
        cout << "| " << left << setw(totalGaris-1) << "4. Update Status Penerbangan" << " |\n";
        cout << "| " << left << setw(totalGaris-1) << "5. Tampilkan Semua Jadwal" << " |\n";
        cout << "| " << left << setw(totalGaris-1) << "0. Keluar" << " |\n";
        cout << "+" << string(totalGaris + 1, '-') << "+\n";

        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahJadwal(); break;
            case 2: sisipJadwal(); break;
            case 3: hapusAwal(); break;
            case 4: updateStatus(); break;
            case 5: tampilkanJadwal(); break;
            case 0: cout << "Keluar dari program, Terima kasih Telah Berkunjung!\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
