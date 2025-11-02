#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
using namespace std;

struct date {
    int tgl, bln, thn;
};

struct stackqueue {
    char nama_brg[30];
    int jumlah;
    struct date tglkedaluwarsa;
};

stackqueue barang[10];
int maxData = 5;
int posisi = 0;

// Menampilkan daftar barang
void tampilkanData() {
    system("cls");
    cout << "==============================\n";
    cout << "    DAFTAR DATA BARANG\n";
    cout << "==============================\n";
    if (posisi == 0) {
        cout << "(Belum ada data barang)\n\n";
    } else {
        for (int i = 0; i < posisi; i++) {
            cout << i + 1 << ". " << barang[i].nama_brg
                 << " | Jumlah: " << barang[i].jumlah
                 << " | Kedaluwarsa: " << barang[i].tglkedaluwarsa.tgl << "/"
                 << barang[i].tglkedaluwarsa.bln << "/"
                 << barang[i].tglkedaluwarsa.thn << endl;
        }
    }
    cout << "==============================\n\n";
}

void pushData() {
    if (posisi == maxData) {
        cout << "Stack/Queue penuh!\n";
        getch();
        return;
    }

    cout << "Masukkan nama barang       : ";
    cin >> barang[posisi].nama_brg;
    cout << "Masukkan jumlah barang     : ";
    cin >> barang[posisi].jumlah;
    cout << "Masukkan tanggal kedaluwarsa (tgl bln thn): ";
    cin >> barang[posisi].tglkedaluwarsa.tgl
        >> barang[posisi].tglkedaluwarsa.bln
        >> barang[posisi].tglkedaluwarsa.thn;

    posisi++;
    cout << "Data berhasil ditambahkan di posisi TOP!\n";
    getch();
}

void popData() {
    if (posisi == 0) {
        cout << "Stack kosong!\n";
        getch();
        return;
    }

    posisi--;
    cout << "Data '" << barang[posisi].nama_brg << "' berhasil dihapus (POP dari TOP-1)\n";
    getch();
}

void dequeueData() {
    if (posisi == 0) {
        cout << "Queue kosong!\n";
        getch();
        return;
    }

    cout << "Data '" << barang[0].nama_brg << "' dihapus dari posisi 1\n";
    for (int i = 0; i < posisi - 1; i++) {
        barang[i] = barang[i + 1];
    }
    posisi--;
    getch();
}

// Special Push/Inqueue (tambah di posisi tengah/N)
void specialPush() {
    if (posisi == maxData) {
        cout << "Stack/Queue penuh!\n";
        getch();
        return;
    }

    int n;
    cout << "Masukkan posisi untuk menambah data (1 - " << posisi + 1 << "): ";
    cin >> n;

    if (n < 1 || n > posisi + 1) {
        cout << "Posisi tidak valid!\n";
        getch();
        return;
    }

    for (int i = posisi; i >= n; i--) {
        barang[i] = barang[i - 1];
    }

    cout << "Masukkan nama barang       : ";
    cin >> barang[n - 1].nama_brg;
    cout << "Masukkan jumlah barang     : ";
    cin >> barang[n - 1].jumlah;
    cout << "Masukkan tanggal kedaluwarsa (tgl bln thn): ";
    cin >> barang[n - 1].tglkedaluwarsa.tgl
        >> barang[n - 1].tglkedaluwarsa.bln
        >> barang[n - 1].tglkedaluwarsa.thn;

    posisi++;
    cout << "Data berhasil ditambahkan di posisi ke-" << n << endl;
    getch();
}

// Special POP/Dequeue (hapus di posisi tengah/N)
void specialPop() {
    if (posisi == 0) {
        cout << "Stack/Queue kosong!\n";
        getch();
        return;
    }

    int n;
    cout << "Masukkan posisi data yang akan dihapus (1 - " << posisi << "): ";
    cin >> n;

    if (n < 1 || n > posisi) {
        cout << "Posisi tidak valid!\n";
        getch();
        return;
    }

    cout << "Data '" << barang[n - 1].nama_brg << "' berhasil dihapus dari posisi ke-" << n << endl;

    for (int i = n - 1; i < posisi - 1; i++) {
        barang[i] = barang[i + 1];
    }

    posisi--;
    getch();
}

// Menu utama
int main() {
    int pilihan;

    do {
        tampilkanData();
        cout << "==============================================\n";
        cout << "              UTS STRUKTUR DATA\n";
        cout << "==============================================\n";
        cout << "1. Push/Inqueue Data\n";
        cout << "2. POP Data\n";
        cout << "3. Dequeue Data\n";
        cout << "4. Special Push/Inqueue\n";
        cout << "5. Special POP/Dequeue\n";
        cout << "6. Selesai\n";
        cout << "----------------------------------------------\n";
        cout << "Pilihan Anda [1-6]: ";
        cin >> pilihan;

        system("cls");

        switch (pilihan) {
            case 1: pushData(); break;
            case 2: popData(); break;
            case 3: dequeueData(); break;
            case 4: specialPush(); break;
            case 5: specialPop(); break;
            case 6: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid!\n"; getch(); break;
        }
    } while (pilihan != 6);

    return 0;
}
