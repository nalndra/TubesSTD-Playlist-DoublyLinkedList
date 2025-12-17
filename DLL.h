#ifndef DLL_H
#define DLL_H

#include <string>
using namespace std;

// ==========================================
// INFOTYPE LAGU
// ==========================================
struct InfotypeLagu {
    string title;
    string artist;
};

// ==========================================
// ELEMENT LAGU
// ==========================================
struct ElmLagu {
    InfotypeLagu info;
    ElmLagu* prev;
    ElmLagu* next;
};

typedef ElmLagu* adrLagu;

// ==========================================
// LIST PLAYLIST
// ==========================================
struct ListPlaylist {
    adrLagu first;
    adrLagu last;
    adrLagu current;  // Pointer ke lagu yang sedang diputar
};

// ==========================================
// FUNGSI-FUNGSI PLAYLIST
// ==========================================

void createListPlaylist(ListPlaylist &L); // Inisialisasi list playlist kosong

adrLagu createElmLagu(InfotypeLagu data); // Membuat elemen lagu baru

void insertLastLagu(ListPlaylist &L, adrLagu P); // Menambah lagu ke akhir playlist

void deleteLaguByTitle(ListPlaylist &L, string title);// Menghapus lagu berdasarkan judul

adrLagu findLagu(ListPlaylist L, string title); // Mencari lagu berdasarkan judul
 
void nextSong(ListPlaylist &L); // Memutar lagu berikutnya

void previousSong(ListPlaylist &L); // Memutar lagu sebelumnya

void displayForward(ListPlaylist L); // Menampilkan playlist dari awal ke akhir

void displayBackward(ListPlaylist L); // Menampilkan playlist dari akhir ke awal

void displayCurrent(ListPlaylist &L); // Menampilkan lagu yang sedang diputar

bool isEmpty(ListPlaylist L); // Mengecek apakah playlist kosong

int getSize(ListPlaylist L); // Mendapatkan jumlah lagu dalam playlist

void clearPlaylist(ListPlaylist &L); // Menghapus semua lagu

#endif // DLL_H
