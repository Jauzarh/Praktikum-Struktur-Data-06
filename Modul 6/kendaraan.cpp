#include "kendaraan.h"
#include <iostream>

using namespace std;

void CreateList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

address alokasi(Kendaraan x) {
    address P = new EImList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

void printlnfo(List L) {
    if (L.First == nullptr) {
        cout << "\nDATA LIST KOSONG\n";
        return;
    }
    
    cout << "\nDATA LIST\n";
    cout << "=======================\n";
    
    address P = L.First;
    int count = 1;
    
    while (P != nullptr) {
        cout << "Kendaraan #" << count << ":\n";
        cout << "  No Polisi: " << P->info.nopol << endl;
        cout << "  Warna    : " << P->info.warna << endl;
        cout << "  Tahun    : " << P->info.thnBuat << endl;
        cout << "-----------------------\n";
        P = P->next;
        count++;
    }
}

void insertLast(List &L, address P) {
    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

bool isNopolExist(List L, std::string nopol) {
    address P = L.First;
    
    while (P != nullptr) {
        if (P->info.nopol == nopol) {
            return true; 
        }
        P = P->next;
    }
    
    return false;  // Nopol tidak ditemukan
}