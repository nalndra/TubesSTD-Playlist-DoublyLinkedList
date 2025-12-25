# 🏥Autopsy Case Manager🩻

Program manajemen kasus autopsi menggunakan struktur data **Doubly Linked List (DLL)** dan **Multi Linked List (MLL)**. Program ini dibuat sebagai tugas besar mata kuliah Struktur Data.

## Deskripsi

Autopsy Case Manager adalah aplikasi berbasis command-line yang memungkinkan forensic analyst untuk mengelola data kasus mayat dengan berbagai operasi seperti menambah kasus, menghapus kasus, mencari kasus, dan menavigasi antar kasus. Program menggunakan konsep Doubly Linked List untuk struktur utama kasus dan Multi Linked List untuk mengelola penyebab kematian pada setiap kasus.

## Fitur Utama

Program ini menyediakan 11 fitur untuk manajemen kasus autopsi:

1. **Tambah Kasus Mayat** - Menambahkan data kasus mayat baru (ID, nama, umur)
2. **Tambah Penyebab Kematian** - Menambahkan penyebab kematian pada kasus tertentu (MLL)
3. **Hapus Kasus** - Menghapus kasus beserta semua penyebab kematiannya
4. **Kasus Berikutnya** - Navigasi ke kasus berikutnya
5. **Kasus Sebelumnya** - Navigasi ke kasus sebelumnya
6. **Tampilkan Arsip (Awal → Akhir)** - Menampilkan semua kasus dari yang terlama
7. **Tampilkan Arsip (Akhir → Awal)** - Menampilkan semua kasus dari yang terbaru
8. **Tampilkan Kasus Sedang Dianalisis** - Menampilkan detail kasus yang sedang aktif
9. **Cari Kasus Mayat** - Mencari kasus berdasarkan ID
10. **Jumlah Kasus dalam Arsip** - Menampilkan total jumlah kasus
11. **Hapus Semua Kasus** - Mengosongkan seluruh arsip

## Struktur Data

### Kasus (Parent)
Struktur data untuk menyimpan informasi kasus mayat:
```cpp
struct Kasus {
    string idKasus;     // ID unik kasus (contoh: K001)
    string namaMayat;   // Nama mayat
    int umur;           // Umur mayat
};
```

### Penyebab (Child)
Struktur data untuk menyimpan penyebab kematian:
```cpp
struct Penyebab {
    string deskripsi;   // Deskripsi penyebab kematian
};
```

### elemenKasus (Node Parent - DLL)
Struktur node untuk Doubly Linked List kasus:
```cpp
struct elemenKasus {
    Kasus info;                 // Data kasus
    adrKasus next;              // Pointer ke kasus berikutnya
    adrKasus prev;              // Pointer ke kasus sebelumnya
    adrPenyebab firstPenyebab;  // Pointer ke list penyebab (MLL)
};
```

### elemenPenyebab (Node Child - DLL)
Struktur node untuk Doubly Linked List penyebab kematian:
```cpp
struct elemenPenyebab {
    Penyebab info;      // Data penyebab
    adrPenyebab next;   // Pointer ke penyebab berikutnya
    adrPenyebab prev;   // Pointer ke penyebab sebelumnya
};
```

### ListKasus (Main List)
Struktur untuk menyimpan daftar kasus:
```cpp
struct ListKasus {
    adrKasus first;     // Pointer ke kasus pertama
    adrKasus last;      // Pointer ke kasus terakhir
};
```

## Requirements

- **Compiler**: g++ (GNU C++ Compiler) atau compiler C++ lainnya
- **OS**: Windows, Linux, atau macOS
- **Standard**: C++11 atau lebih baru

## Cara Kompilasi dan Menjalankan

### Windows (PowerShell/CMD)

1. **Kompilasi program:**
   ```powershell
   g++ -o autopsy main.cpp MLL.cpp
   ```

2. **Jalankan program:**
   ```powershell
   .\autopsy.exe
   ```

### Linux/macOS

1. **Kompilasi program:**
   ```bash
   g++ -o autopsy main.cpp MLL.cpp
   ```

2. **Jalankan program:**
   ```bash
   ./autopsy
   ```

## Cara Penggunaan

1. **Jalankan program** menggunakan perintah di atas
2. Pilih menu dengan memasukkan angka (1-11 atau 0 untuk exit)
3. Ikuti instruksi yang muncul di layar

### Contoh Menu

```
============================================================
                AUTOPSY CASE MANAGER
============================================================
 [1] Tambah Kasus Mayat
 [2] Tambah Penyebab Kematian
 [3] Hapus Kasus
 [4] Kasus Berikutnya
 [5] Kasus Sebelumnya
 [6] Tampilkan Arsip (Awal -> Akhir)
 [7] Tampilkan Arsip (Akhir -> Awal)
 [8] Tampilkan Kasus Sedang Dianalisis
 [9] Cari Kasus Mayat
 [10] Jumlah Kasus dalam Arsip
 [11] Hapus Semua Kasus
 [0] Exit
============================================================
```

### Contoh Penggunaan

**Menambah Kasus Baru:**
```
Pilihan Anda : 1
ID Kasus   : K004
Nama Mayat : Sarah Johnson
Umur       : 28
```

**Menambah Penyebab Kematian:**
```
Pilihan Anda : 2
Masukkan ID Kasus: K004
Jumlah penyebab: 2
Penyebab ke-1: Luka tusuk di dada
Penyebab ke-2: Pendarahan masif
Penyebab berhasil ditambahkan.
```

**Menampilkan Kasus Sedang Dianalisis:**
```
Pilihan Anda : 8
ID Kasus : K001
Nama     : John Doe
Umur     : 45
Penyebab Kematian: Trauma kepala berat, Pendarahan internal,
```

## Fungsi-Fungsi Utama

### Operasi List Kasus (DLL)
| Fungsi | Deskripsi |
|--------|-----------|
| `createListKasus(ListKasus &L)` | Inisialisasi list kasus kosong |
| `isEmptyKasus(ListKasus L)` | Mengecek apakah list kasus kosong |
| `createElemenKasus(string id, string nama, int umur)` | Membuat elemen kasus baru |
| `addKasus(ListKasus &L, adrKasus p)` | Menambah kasus ke akhir list |
| `deleteKasus(ListKasus &L, adrKasus &current)` | Menghapus kasus beserta child-nya |
| `searchKasus(ListKasus L, string id)` | Mencari kasus berdasarkan ID |
| `countKasus(ListKasus L)` | Menghitung jumlah kasus |
| `deleteAllKasus(ListKasus &L)` | Menghapus semua kasus |

### Operasi Penyebab Kematian (MLL Child)
| Fungsi | Deskripsi |
|--------|-----------|
| `isEmptyPenyebab(adrKasus p)` | Mengecek apakah list penyebab kosong |
| `createElemenPenyebab(string sebab)` | Membuat elemen penyebab baru |
| `addPenyebab(adrKasus &p, adrPenyebab q)` | Menambah penyebab ke kasus tertentu |

### Navigasi & Display
| Fungsi | Deskripsi |
|--------|-----------|
| `nextKasus(adrKasus &current)` | Navigasi ke kasus berikutnya |
| `prevKasus(adrKasus &current)` | Navigasi ke kasus sebelumnya |
| `displayKasus(adrKasus p)` | Menampilkan detail satu kasus |
| `displayList(ListKasus L)` | Menampilkan semua kasus (forward) |

## Konsep Struktur Data yang Diterapkan

### Doubly Linked List (DLL)
- Insert di akhir list (insert last)
- Delete node tertentu dengan update pointer prev/next
- Traversal forward (first → last)
- Traversal backward (last → first)
- Navigasi prev dan next dengan pointer bidirectional

### Multi Linked List (MLL)
- Parent-Child relationship (Kasus → Penyebab)
- One-to-Many relationship (satu kasus bisa punya banyak penyebab)
- Child list sebagai Doubly Linked List
- Cascade delete (hapus parent, semua child ikut terhapus)

### Operasi Lanjutan
- Search berdasarkan key (ID Kasus)
- Count nodes in list
- Clear entire list (delete all)
- Current pointer untuk tracking kasus aktif

## Catatan Penting

- **Case-Sensitive**: Pencarian ID kasus bersifat case-sensitive
- **Current Pointer**: Pointer `current` otomatis terupdate saat:
  - Menambah kasus baru → set ke kasus yang baru ditambahkan
  - Kasus dihapus → berpindah ke next atau prev
  - Navigasi next/prev → berpindah sesuai arah
  - Mencari kasus → set ke kasus yang ditemukan
- **Cascade Delete**: Menghapus kasus akan otomatis menghapus semua penyebab kematiannya
- **Validasi**: Program akan memberikan notifikasi jika operasi tidak valid (contoh: kasus tidak ditemukan, navigasi dari list kosong)

## Authors

**Adrian Anis Pratama**  
**Nalendra Magi Jatayu**  
Students of Telkom University

**Tugas Besar Struktur Data**  
Program Autopsy Case Manager dengan implementasi Doubly Linked List dan Multi Linked List

## License

Program ini dibuat untuk keperluan edukasi dan pembelajaran Struktur Data.

---

**Repository**: MLL_Autopsy-Case-Manager
**Last Updated**: December 25, 2025

