#include "DLL.h"
#include <iostream>
using namespace std;

// ==========================================
// PLAYLIST LAGU
// ==========================================

// Inisialisasi list playlist kosong
void createListPlaylist(ListPlaylist &L) {
    L.first = NULL;
    L.last = NULL;
    L.current = NULL;
}

// Membuat elemen lagu baru
adrLagu createElmLagu(InfotypeLagu data) {
    adrLagu P = new ElmLagu;
    P->info = data;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

// Menambah lagu ke akhir playlist
void insertLastLagu(ListPlaylist &L, adrLagu P) {
    if (L.first == NULL && L.last == NULL) {
        // Jika playlist kosong
        L.first = P;
        L.last = P;
        L.current = P;  // Set current ke lagu pertama
    } else {
        // Menambahkan node baru di akhir
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

// Menghapus lagu berdasarkan judul
void deleteLaguByTitle(ListPlaylist &L, string title) {
    if (L.first == NULL && L.last == NULL) {
        return;
    }

    // Cari pointer lagu yang akan dihapus
    adrLagu P = findLagu(L, title);

    if (P == NULL) {
        return;
    }

    // Jika node yang dihapus adalah current, pindahkan current
    if (P == L.current) {
        if (L.current->next != NULL) {
            L.current = L.current->next;
        } else if (L.current->prev != NULL) {
            L.current = L.current->prev;
        } else {
            L.current = NULL;  // Playlist akan kosong
        }
    }

    // Menghapus node dari linked list
    if (P == L.first && P == L.last) {
        // Case: Hanya ada 1 elemen dalam list
        L.first = NULL;
        L.last = NULL;
    } else if (P == L.first) {
        // Case: Hapus elemen pertama
        L.first = P->next;
        L.first->prev = NULL;
    } else if (P == L.last) {
        // Case: Hapus elemen terakhir
        L.last = P->prev;
        L.last->next = NULL;
    } else {
        // Case: Hapus elemen di tengah
        adrLagu prec = P->prev;
        adrLagu succ = P->next;
        prec->next = succ;
        succ->prev = prec;
    }

    delete P;
}

// Mencari lagu berdasarkan judul
adrLagu findLagu(ListPlaylist L, string title) {
    adrLagu P = L.first;
    while (P != NULL) {
        if (P->info.title == title) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

// Memutar lagu berikutnya
void nextSong(ListPlaylist &L) {
    if (L.first == NULL && L.last == NULL) {
        return;
    }

    if (L.current == NULL) {
        L.current = L.first;
    } else if (L.current->next != NULL) {
        L.current = L.current->next;
    } else {
        // Jika sudah di akhir, kembali ke awal (circular)
        L.current = L.first;
    }

    displayCurrent(L);
}

// Memutar lagu sebelumnya
void previousSong(ListPlaylist &L) {
    if (L.first == NULL && L.last == NULL) {
        return;
    }

    if (L.current == NULL) {
        L.current = L.last;
    } else if (L.current->prev != NULL) {
        L.current = L.current->prev;
    } else {
        // Jika sudah di awal, pindah ke akhir (circular)
        L.current = L.last;
    }

    displayCurrent(L);
}

// Menampilkan playlist dari awal ke akhir
void displayForward(ListPlaylist L) {
    if (L.first == NULL && L.last == NULL) {
        return;
    }

    cout << "\n========================================================" << endl;
    cout << "        PLAYLIST (Awal -> Akhir)" << endl;
    cout << "--------------------------------------------------------" << endl;
    adrLagu P = L.first;
    int index = 1;

    while (P != NULL) {
        cout << "  " << index << ". " << P->info.title << " - " << P->info.artist;
        if (P == L.current) {
            cout << " [SEDANG DIPUTAR]";
        }
        cout << endl;
        P = P->next;
        index++;
    }
    cout << "--------------------------------------------------------" << endl;
    cout << "Total: " << getSize(L) << " lagu" << endl;
    cout << "========================================================\n" << endl;
}

// Menampilkan playlist dari akhir ke awal
void displayBackward(ListPlaylist L) {
    if (L.first == NULL && L.last == NULL) {
        return;
    }

    cout << "\n========================================================" << endl;
    cout << "        PLAYLIST (Akhir -> Awal)" << endl;
    cout << "--------------------------------------------------------" << endl;
    adrLagu P = L.last;
    int index = getSize(L);

    while (P != NULL) {
        cout << "  " << index << ". " << P->info.title << " - " << P->info.artist;
        if (P == L.current) {
            cout << " [SEDANG DIPUTAR]";
        }
        cout << endl;
        P = P->prev;
        index--;
    }
    cout << "--------------------------------------------------------" << endl;
    cout << "Total: " << getSize(L) << " lagu" << endl;
    cout << "========================================================\n" << endl;
}

// Menampilkan lagu yang sedang diputar
void displayCurrent(ListPlaylist &L) {
    if (L.first == NULL && L.last == NULL) {
        return;
    }

    if (L.current == NULL) {
        L.current = L.first;
    }

    cout << "\n========================================================" << endl;
    cout << "              SEDANG DIPUTAR" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "  " << L.current->info.title << " - " << L.current->info.artist << endl;
    cout << "========================================================\n" << endl;
}

// Mengecek apakah playlist kosong
bool isEmpty(ListPlaylist L) {
    return (L.first == NULL && L.last == NULL);
}

// Mendapatkan jumlah lagu dalam playlist
int getSize(ListPlaylist L) {
    int count = 0;
    adrLagu P = L.first;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

// Menghapus semua lagu
void clearPlaylist(ListPlaylist &L) {
    adrLagu P = L.first;
    while (P != NULL) {
        adrLagu next = P->next;
        delete P;
        P = next;
    }
    L.first = NULL;
    L.last = NULL;
    L.current = NULL;
}
