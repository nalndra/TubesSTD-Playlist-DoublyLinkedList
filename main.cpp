#include "DLL.h"
#include <iostream>
using namespace std;

void printMenu() {
    cout << "\n";
    cout << "========================================================" << endl;
    cout << "           MUSIC PLAYLIST MANAGER" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "  [1]  Tambah Lagu" << endl;
    cout << "  [2]  Hapus Lagu" << endl;
    cout << "  [3]  Next Song" << endl;
    cout << "  [4]  Previous Song" << endl;
    cout << "  [5]  Tampilkan Playlist (Awal -> Akhir)" << endl;
    cout << "  [6]  Tampilkan Playlist (Akhir -> Awal)" << endl;
    cout << "  [7]  Tampilkan Lagu yang Sedang Diputar" << endl;
    cout << "  [8]  Cari Lagu" << endl;
    cout << "  [9]  Jumlah Lagu dalam Playlist" << endl;
    cout << "  [10] Hapus Semua Lagu" << endl;
    cout << "  [0]  Exit" << endl;
    cout << "========================================================" << endl;
    cout << "Pilihan Anda: ";
}

void initData(ListPlaylist &L) {
    // Inisialisasi beberapa lagu populer sebagai contoh
    insertLastLagu(L, createElmLagu({"Bohemian Rhapsody", "Queen"}));
    insertLastLagu(L, createElmLagu({"Hotel California", "Eagles"}));
    insertLastLagu(L, createElmLagu({"Stairway to Heaven", "Led Zeppelin"}));
    insertLastLagu(L, createElmLagu({"TABOLA BALE", "Silet Open Up, Jacson Seran, Juan Reza & Diva Aurel"}));
    insertLastLagu(L, createElmLagu({"Billie Jean", "Michael Jackson"}));
    insertLastLagu(L, createElmLagu({"Sweet Child O' Mine", "Guns N' Roses"}));
    insertLastLagu(L, createElmLagu({"Smells Like Teen Spirit", "Nirvana"}));
    insertLastLagu(L, createElmLagu({"Wonderwall", "Oasis"}));
    insertLastLagu(L, createElmLagu({"Nina", ".feast"}));
    
    cout << "[Init] Data playlist berhasil diinisialisasi dengan " << getSize(L) << " lagu." << endl;
}

int main() {
    // 1. Inisiasi saat kode pertama kali dijalankan
    ListPlaylist L;
    createListPlaylist(L);
    
    initData(L);
    
    int choice;
    do {
        printMenu();
        cin >> choice;
        
        if (choice == 1) {
            InfotypeLagu data;
            cout << "Judul Lagu: "; 
            cin.ignore(); 
            getline(cin, data.title);
            cout << "Nama Artis: "; 
            getline(cin, data.artist);
            
            adrLagu P = createElmLagu(data);
            insertLastLagu(L, P);
            cout << "[Success] Lagu \"" << data.title << "\" oleh " << data.artist << " ditambahkan." << endl;
            
        } else if (choice == 2) {
            if (isEmpty(L)) {
                cout << "[Warning] Playlist kosong! Tidak ada lagu yang bisa dihapus." << endl;
            } else {
                string title;
                cout << "Masukkan judul lagu yang akan dihapus: "; 
                cin.ignore(); 
                getline(cin, title);
                
                adrLagu found = findLagu(L, title);
                if (found != NULL) {
                    deleteLaguByTitle(L, title);
                    cout << "[Success] Lagu \"" << title << "\" berhasil dihapus dari playlist." << endl;
                } else {
                    cout << "[Error] Lagu \"" << title << "\" tidak ditemukan dalam playlist." << endl;
                }
            }
            
        } else if (choice == 3) {
            if (isEmpty(L)) {
                cout << "[Warning] Playlist kosong! Tidak ada lagu untuk diputar." << endl;
            } else {
                nextSong(L);
            }
            
        } else if (choice == 4) {
            if (isEmpty(L)) {
                cout << "[Warning] Playlist kosong! Tidak ada lagu untuk diputar." << endl;
            } else {
                previousSong(L);
            }
            
        } else if (choice == 5) {
            displayForward(L);
            
        } else if (choice == 6) {
            displayBackward(L);
            
        } else if (choice == 7) {
            if (isEmpty(L)) {
                cout << "[Warning] Playlist kosong! Tidak ada lagu yang sedang diputar." << endl;
            } else {
                displayCurrent(L);
            }
            
        } else if (choice == 8) {
            if (isEmpty(L)) {
                cout << "[Warning] Playlist kosong!" << endl;
            } else {
                string title;
                cout << "Masukkan judul lagu yang dicari: "; 
                cin.ignore(); 
                getline(cin, title);
                
                adrLagu found = findLagu(L, title);
                if (found != NULL) {
                    cout << "[Found] Lagu ditemukan!" << endl;
                    cout << "   Judul: " << found->info.title << endl;
                    cout << "   Artis: " << found->info.artist << endl;
                } else {
                    cout << "[Not Found] Lagu \"" << title << "\" tidak ditemukan dalam playlist." << endl;
                }
            }
            
        } else if (choice == 9) {
            cout << "[Info] Jumlah lagu dalam playlist: " << getSize(L) << " lagu" << endl;
            
        } else if (choice == 10) {
            if (isEmpty(L)) {
                cout << "[Warning] Playlist sudah kosong!" << endl;
            } else {
                cout << "[Warning] Menghapus semua lagu akan mengosongkan playlist!" << endl;
                clearPlaylist(L);
                cout << "[Success] Semua lagu berhasil dihapus. Playlist sekarang kosong." << endl;
            }
            
        } else if (choice == 0) {
            cout << "[Info] Program selesai. Terima kasih telah menggunakan Music Playlist Manager!" << endl;
        } else {
            cout << "[Error] Pilihan tidak valid! Silakan pilih menu yang tersedia." << endl;
        }
        
    } while (choice != 0);
    
    return 0;
}
