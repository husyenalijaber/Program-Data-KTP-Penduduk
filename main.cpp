#include <iostream>
#include <string>
using namespace std;

// Definisi struct KTP
struct KTP {
    string nama;
    string alamat;
    string nomorKTP;
};

// Deklarasi fungsi
void tambahData(KTP data[], int &jumlahData);
void cariData(KTP data[], int jumlahData);
void tampilkanData(KTP data[], int jumlahData);
void hapusData(KTP data[], int &jumlahData);

int main() {
    const int MAX_DATA = 100;
    KTP data[MAX_DATA];
    int jumlahData = 0;
    int pilihan;

    do {
        cout << "\n=== Menu Data KTP Penduduk ===" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Cari Data" << endl;
        cout << "3. Tampilkan Data" << endl;
        cout << "4. Hapus Data" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahData(data, jumlahData);
                break;
            case 2:
                cariData(data, jumlahData);
                break;
            case 3:
                tampilkanData(data, jumlahData);
                break;
            case 4:
                hapusData(data, jumlahData);
                break;
            case 5:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }

    } while (pilihan != 5);

    return 0;
}

void tambahData(KTP data[], int &jumlahData) {
    if (jumlahData == 100) {
        cout << "Maaf, kapasitas data sudah penuh!" << endl;
        return;
    }

    cout << "\nMasukkan data KTP baru:" << endl;
    cout << "Nama: ";
    cin.ignore();
    getline(cin, data[jumlahData].nama);
    cout << "Alamat: ";
    getline(cin, data[jumlahData].alamat);
    cout << "Nomor KTP: ";
    cin >> data[jumlahData].nomorKTP;

    jumlahData++;
    cout << "Data berhasil ditambahkan!" << endl;
}

void cariData(KTP data[], int jumlahData) {
    string nomorKTP;
    cout << "\nMasukkan nomor KTP yang ingin dicari: ";
    cin >> nomorKTP;

    bool ditemukan = false;
    for (int i = 0; i < jumlahData; i++) {
        if (data[i].nomorKTP == nomorKTP) {
            cout << "Data ditemukan:" << endl;
            cout << "Nama: " << data[i].nama << endl;
            cout << "Alamat: " << data[i].alamat << endl;
            cout << "Nomor KTP: " << data[i].nomorKTP << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Data tidak ditemukan!" << endl;
    }
}

void tampilkanData(KTP data[], int jumlahData) {
    if (jumlahData == 0) {
        cout << "\nTidak ada data KTP penduduk!" << endl;
        return;
    }

    cout << "\nData KTP Penduduk:" << endl;
    for (int i = 0; i < jumlahData; i++) {
        cout << "Data ke-" << i + 1 << endl;
        cout << "Nama: " << data[i].nama << endl;
        cout << "Alamat: " << data[i].alamat << endl;
        cout << "Nomor KTP: " << data[i].nomorKTP << endl;
        cout << "-----------------------------" << endl;
    }
}

void hapusData(KTP data[], int &jumlahData) {
    string nomorKTP;
    cout << "\nMasukkan nomor KTP data yang ingin dihapus: ";
    cin >> nomorKTP;

    int indeks = -1;
    for (int i = 0; i < jumlahData; i++) {
        if (data[i].nomorKTP == nomorKTP) {
            indeks = i;
            break;
        }
    }

    if (indeks == -1) {
        cout << "Data tidak ditemukan!" << endl;
        return;
    }

    // Menggeser data setelah indeks yang dihapus ke kiri
    for (int i = indeks; i < jumlahData - 1; i++) {
        data[i] = data[i + 1];
    }
    jumlahData--;
    cout << "Data berhasil dihapus!" << endl;
}
