#include "DLL.h"

void createListKasus(ListKasus &L)
{
    L.first = nullptr;
    L.last = nullptr;
}

bool isEmptyKasus(ListKasus L)
{
    return L.first == nullptr;
}

bool isEmptyPenyebab(adrKasus p)
{
    return p->firstPenyebab == nullptr;
}

adrKasus createElemenKasus(string id, string nama, int umur)
{
    adrKasus p = new elemenKasus;
    p->info.idKasus = id;
    p->info.namaMayat = nama;
    p->info.umur = umur;
    p->next = nullptr;
    p->prev = nullptr;
    p->firstPenyebab = nullptr;
    return p;
}

adrPenyebab createElemenPenyebab(string sebab)
{
    adrPenyebab q = new elemenPenyebab;
    q->info.deskripsi = sebab;
    q->next = nullptr;
    q->prev = nullptr;
    return q;
}

void addKasus(ListKasus &L, adrKasus p)
{
    if (isEmptyKasus(L))
    {
        L.first = p;
        L.last = p;
    }
    else
    {
        L.last->next = p;
        p->prev = L.last;
        L.last = p;
    }
}

void addPenyebab(adrKasus &p, adrPenyebab q)
{
    if (isEmptyPenyebab(p))
    {
        p->firstPenyebab = q;
    }
    else
    {
        adrPenyebab r = p->firstPenyebab;
        while (r->next != nullptr)
        {
            r = r->next;
        }
        r->next = q;
        q->prev = r;
    }
}

adrKasus searchKasus(ListKasus L, string id)
{
    adrKasus p = L.first;
    while (p != nullptr)
    {
        if (p->info.idKasus == id)
        {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void displayList(ListKasus L)
{
    adrKasus p = L.first;
    while (p != nullptr)
    {
        cout << "Kasus ID   : " << p->info.idKasus << endl;
        cout << "Nama Mayat : " << p->info.namaMayat << endl;
        cout << "Umur       : " << p->info.umur << endl;

        cout << "Penyebab Kematian: ";
        adrPenyebab q = p->firstPenyebab;
        while (q != nullptr)
        {
            cout << q->info.deskripsi << ", ";
            q = q->next;
        }
        cout << endl
             << endl;

        p = p->next;
    }
}

void displayKasus(adrKasus p)
{
    if (p == nullptr)
    {
        cout << "Tidak ada kasus aktif.\n";
        return;
    }

    cout << "ID Kasus : " << p->info.idKasus << endl;
    cout << "Nama     : " << p->info.namaMayat << endl;
    cout << "Umur     : " << p->info.umur << endl;

    cout << "Penyebab Kematian: ";
    adrPenyebab q = p->firstPenyebab;
    while (q != nullptr)
    {
        cout << q->info.deskripsi << ", ";
        q = q->next;
    }
    cout << endl;
}

void nextKasus(adrKasus &current)
{
    if (current && current->next)
        current = current->next;
    else
        cout << "Tidak ada kasus berikutnya.\n";
}

void prevKasus(adrKasus &current)
{
    if (current && current->prev)
        current = current->prev;
    else
        cout << "Tidak ada kasus sebelumnya.\n";
}

void deleteKasus(ListKasus &L, adrKasus &current)
{
    if (current == nullptr)
    {
        cout << "Tidak ada kasus yang bisa dihapus.\n";
        return;
    }

    adrKasus p = current;

    if (p == L.first)
        L.first = p->next;
    if (p == L.last)
        L.last = p->prev;

    if (p->prev)
        p->prev->next = p->next;
    if (p->next)
        p->next->prev = p->prev;

    current = (p->next != nullptr) ? p->next : p->prev;

    // hapus child
    adrPenyebab q;
    while (p->firstPenyebab != nullptr)
    {
        q = p->firstPenyebab;
        p->firstPenyebab = q->next;
        delete q;
    }

    delete p;
    cout << "Kasus berhasil dihapus.\n";
}

int countKasus(ListKasus L)
{
    int count = 0;
    adrKasus p = L.first;
    while (p != nullptr)
    {
        count++;
        p = p->next;
    }
    return count;
}

void deleteAllKasus(ListKasus &L)
{
    adrKasus p = L.first;
    while (p != nullptr)
    {
        adrKasus temp = p;
        p = p->next;
        deleteKasus(L, temp);
    }
    L.first = nullptr;
    L.last = nullptr;
}
