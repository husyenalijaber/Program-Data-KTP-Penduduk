# 📘 Program Data KTP Penduduk

Program ini dibuat menggunakan **C++** untuk mengelola data KTP penduduk secara sederhana.
Pengguna dapat **menambah, mencari, menampilkan, dan menghapus data** yang tersimpan dalam array statis.

---

## 🧩 Fitur Utama

1. **Tambah Data KTP**
   * Memasukkan data baru berupa *nama*, *alamat*, dan *nomor KTP*.
   * Data disimpan di array selama program berjalan.

2. **Cari Data KTP**
   * Mencari data berdasarkan *nomor KTP* yang dimasukkan pengguna.

3. **Tampilkan Semua Data**
   * Menampilkan seluruh data KTP yang tersimpan dalam format terurut.

4. **Hapus Data KTP**
   * Menghapus data berdasarkan *nomor KTP* yang dipilih pengguna.
   * Data setelahnya akan otomatis bergeser.

5. **Keluar Program**
   * Mengakhiri program dengan pesan “Terima kasih!”.

---

## ⚙️ Cara Menjalankan

### 1️⃣ Kompilasi program

Buka terminal atau command prompt, lalu jalankan perintah:

```bash
g++ main.cpp -o ktp_app
```

### 2️⃣ Jalankan program

```bash
./ktp_app
```

*(Untuk Windows bisa jalankan `ktp_app.exe`)*

---

## 🗂️ Struktur Program

```
📁 Program_KTP/
│
├── main.cpp          # File utama berisi kode program
├── README.md         # Dokumentasi proyek
```

---

## 🧠 Penjelasan Singkat Kode

* **Struct KTP**
  Menyimpan data individu dengan atribut:

  ```cpp
  struct KTP {
      string nama;
      string alamat;
      string nomorKTP;
  };
  ```

* **Array Data**
  Program menampung hingga **100 data** penduduk:

  ```cpp
  KTP data[100];
  int jumlahData = 0;
  ```

* **Fungsi Utama**
  * `tambahData()` → Input data baru.
  * `cariData()` → Pencarian berdasarkan nomor KTP.
  * `tampilkanData()` → Menampilkan semua data.
  * `hapusData()` → Menghapus data berdasarkan nomor KTP.

---

## 🧾 Contoh Tampilan Menu

```
=== Menu Data KTP Penduduk ===
1. Tambah Data
2. Cari Data
3. Tampilkan Data
4. Hapus Data
5. Keluar
Pilihan:
```

---

## 💡 Catatan

* Data **tidak disimpan permanen**, hanya ada selama program berjalan.
* Kapasitas maksimum adalah **100 data**.
* Gunakan *nomor KTP unik* agar tidak terjadi duplikasi data.

---

## 🚀 Pengembangan Lanjutan (Opsional)

Beberapa ide pengembangan yang bisa kamu tambahkan:
- Simpan & baca data dari file `.txt` menggunakan `ofstream` dan `ifstream`.
- Ganti penyimpanan array ke **vector** agar lebih fleksibel.
- Tambahkan **validasi input** (misalnya panjang nomor KTP harus 16 digit).
- Gunakan **class** agar kode lebih modular.

---
