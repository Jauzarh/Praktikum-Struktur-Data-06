#ifndef kendaraan_H
#define kendaraan_H

#include <string>

struct Kendaraan {
    std::string nopol;
    std::string warna;
    int thnBuat;
};

struct EImList {
    Kendaraan info;
    EImList* next;
    EImList* prev;
};

typedef EImList* address;

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(Kendaraan x);
void dealokasi(address &P);
void printlnfo(List L);
void insertLast(List &L, address P);
bool isNopolExist(List L, std::string nopol);

#endif