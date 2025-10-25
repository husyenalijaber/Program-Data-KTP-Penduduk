#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct KTP {
    string nama;
    string alamat;
    string nomorKTP;
};

void simpanData(KTP data[], int jumlahData);
void bacaData(KTP data[], int &jumlahData);
void tambahData(KTP data[], int &jumlahData);
void cariData(KTP data[], int jumlahData);
void tampilkanData(KTP data[], int jumlahData);
void hapusData(KTP data[], int &jumlahData);

int main() {
    const int MAX_DATA = 100;
    KTP data[MAX_DATA];
    int jumlahData = 0;
    int pilihan;

    bacaData(data, jumlahData);

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
                simpanData(data, jumlahData);
                break;
            case 2:
                cariData(data, jumlahData);
                break;
            case 3:
                tampilkanData(data, jumlahData);
                break;
            case 4:
                hapusData(data, jumlahData);
                simpanData(data, jumlahData);
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

void simpanData(KTP data[], int jumlahData) {
    ofstream file("data_ktp.txt");
    if (!file.is_open()) {
        cout << "Gagal membuka file untuk menyimpan data!" << endl;
        return;
    }

    for (int i = 0; i < jumlahData; i++) {
        file << data[i].nama << "|" << data[i].alamat << "|" << data[i].nomorKTP << "\n";
    }

    file.close();
    cout << "✅ Data berhasil disimpan ke file!" << endl;
}

void bacaData(KTP data[], int &jumlahData) {
    ifstream file("data_ktp.txt");
    if (!file.is_open()) {
        cout << "(Belum ada file data, akan dibuat baru nanti.)" << endl;
        return;
    }

    jumlahData = 0;
    string line;
    while (getline(file, line)) {
        size_t pos1 = line.find('|');
        size_t pos2 = line.rfind('|');
        if (pos1 != string::npos && pos2 != string::npos && pos1 != pos2) {
            data[jumlahData].nama = line.substr(0, pos1);
            data[jumlahData].alamat = line.substr(pos1 + 1, pos2 - pos1 - 1);
            data[jumlahData].nomorKTP = line.substr(pos2 + 1);
            jumlahData++;
        }
    }
    file.close();
    cout << "📂 Data berhasil dibaca dari file (" << jumlahData << " data)." << endl;
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
    cout << "✅ Data berhasil ditambahkan!" << endl;
}

void cariData(KTP data[], int jumlahData) {
    string nomorKTP;
    cout << "\nMasukkan nomor KTP yang ingin dicari: ";
    cin >> nomorKTP;

    bool ditemukan = false;
    for (int i = 0; i < jumlahData; i++) {
        if (data[i].nomorKTP == nomorKTP) {
            cout << "🔍 Data ditemukan:" << endl;
            cout << "Nama: " << data[i].nama << endl;
            cout << "Alamat: " << data[i].alamat << endl;
            cout << "Nomor KTP: " << data[i].nomorKTP << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "⚠️ Data tidak ditemukan!" << endl;
    }
}

void tampilkanData(KTP data[], int jumlahData) {
    if (jumlahData == 0) {
        cout << "\nTidak ada data KTP penduduk!" << endl;
        return;
    }

    cout << "\n📋 Data KTP Penduduk:" << endl;
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
        cout << "⚠️ Data tidak ditemukan!" << endl;
        return;
    }

    for (int i = indeks; i < jumlahData - 1; i++) {
        data[i] = data[i + 1];
    }
    jumlahData--;
    cout << "🗑️ Data berhasil dihapus!" << endl;
}
