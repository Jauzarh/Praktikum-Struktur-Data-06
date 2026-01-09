#include "kendaraan.h"
#include "kendaraan.cpp"
#include <iostream>
#include <limits>

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void displayMenu() {
    cout << "\n=== MENU MANAJEMEN KENDARAAN ===\n";
    cout << "1. Tambah Data Kendaraan\n";
    cout << "2. Tampilkan Semua Data\n";
    cout << "3. Keluar\n";
    cout << "Pilihan: ";
}

Kendaraan inputKendaraan() {
    Kendaraan k;
    
    cout << "\n--- Input Data Kendaraan ---\n";
    
    cout << "Masukkan nomor polisi: ";
    getline(cin, k.nopol);
    
    cout << "Masukkan warna kendaraan: ";
    getline(cin, k.warna);
    
    cout << "Masukkan tahun kendaraan: ";
    while (!(cin >> k.thnBuat)) {
        cout << "Input tahun harus angka! Coba lagi: ";
        cin.clear();
        clearInputBuffer();
    }
    clearInputBuffer();
    
    return k;
}

int main() {
    List L;
    CreateList(L);
    int choice;
    
    do {
        displayMenu();
        cin >> choice;
        clearInputBuffer();
        
        switch (choice) {
            case 1: {
                Kendaraan newKendaraan = inputKendaraan();
                
                if (isNopolExist(L, newKendaraan.nopol)) {
                    cout << "\nNomor polisi \"" << newKendaraan.nopol 
                         << "\" sudah terdaftar!\n";
                } else {
                    address newNode = alokasi(newKendaraan);
                    insertLast(L, newNode);
                    cout << "\nData kendaraan berhasil ditambahkan!\n";
                }
                break;
            }
            
            case 2:
                printlnfo(L);
                break;
                
            case 3:
                cout << "\nProgram selesai.\n";
                break;
                
            default:
                cout << "\nPilihan tidak valid!\n";
        }
        
    } while (choice != 3);
    
    address current = L.First;
    while (current != nullptr) {
        address nextNode = current->next;
        dealokasi(current);
        current = nextNode;
    }
    
    return 0;
}