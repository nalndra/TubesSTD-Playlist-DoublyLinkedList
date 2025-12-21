#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED
#include <iostream>
using namespace std;

typedef struct elemenKasus *adrKasus;
typedef struct elemenPenyebab *adrPenyebab;

struct Kasus
{
    string idKasus;
    string namaMayat;
    int umur;
};
struct Penyebab
{
    string deskripsi;
};
struct elemenKasus
{
    Kasus info;
    adrKasus next;
    adrKasus prev;
    adrPenyebab firstPenyebab;
};
struct elemenPenyebab
{
    Penyebab info;
    adrPenyebab next;
    adrPenyebab prev;
};
struct ListKasus
{
    adrKasus first;
    adrKasus last;
};

void createListKasus(ListKasus &L);
bool isEmptyKasus(ListKasus L);
bool isEmptyPenyebab(adrKasus p);

adrKasus createElemenKasus(string id, string nama, int umur);
adrPenyebab createElemenPenyebab(string sebab);

void addKasus(ListKasus &L, adrKasus p);
void addPenyebab(adrKasus &p, adrPenyebab q);

adrKasus searchKasus(ListKasus L, string id);
void displayList(ListKasus L);

void deleteKasus(ListKasus &L, adrKasus &current);
void nextKasus(adrKasus &current);
void prevKasus(adrKasus &current);
void displayKasus(adrKasus p);
int countKasus(ListKasus L);
void deleteAllKasus(ListKasus &L);

#endif
