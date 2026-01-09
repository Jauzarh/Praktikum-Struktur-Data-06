#include "playlist.h"
#include <iostream>
#include <limits>

using namespace std;

void displayMainMenu() {
    cout << "\n=== MANAJEMEN PLAYLIST LAGU ===\n";
    cout << "1. Tambah Lagu\n";
    cout << "2. Hapus Lagu Berdasarkan Judul\n";
    cout << "3. Tampilkan Seluruh Lagu\n";
    cout << "4. Keluar\n";
    cout << "Pilihan Anda: ";
}

void displayAddSongMenu() {
    cout << "\n=== PILIHAN TAMBAH LAGU ===\n";
    cout << "1. Tambah di Awal Playlist\n";
    cout << "2. Tambah di Akhir Playlist\n";
    cout << "3. Tambah Setelah Lagu ke-3\n";
    cout << "4. Kembali ke Menu Utama\n";
    cout << "Pilihan Anda: ";
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void addSongProcess(Playlist& playlist, int addChoice) {
    string title, artist;
    float duration;
    
    cout << "\n--- Tambah Lagu ---\n";
    cout << "Judul lagu: ";
    getline(cin, title);
    cout << "Nama penyanyi: ";
    getline(cin, artist);
    cout << "Durasi (menit): ";
    cin >> duration;
    clearInputBuffer();
    
    switch(addChoice) {
        case 1:
            playlist.addFirst(title, artist, duration);
            break;
        case 2:
            playlist.addLast(title, artist, duration);
            break;
        case 3:
            playlist.addAfterThird(title, artist, duration);
            break;
        default:
            cout << "Pilihan tidak valid!\n";
    }
}

int main() {
    Playlist myPlaylist;
    int choice, addChoice;
    string title;

    do {
        displayMainMenu();
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            clearInputBuffer();
            cout << "Input tidak valid! Silakan masukkan angka.\n";
            continue;
        }

        clearInputBuffer();

        switch (choice) {
            case 1: // Menu Tambah Lagu
                do {
                    displayAddSongMenu();
                    cin >> addChoice;
                    
                    if (cin.fail()) {
                        cin.clear();
                        clearInputBuffer();
                        cout << "Input tidak valid! Silakan masukkan angka.\n";
                        continue;
                    }
                    
                    clearInputBuffer();
                    
                    if (addChoice == 4) {
                        cout << "Kembali ke menu utama...\n";
                        break;
                    }
                    
                    if (addChoice >= 1 && addChoice <= 3) {
                        addSongProcess(myPlaylist, addChoice);
                        cout << "\nTekan Enter untuk melanjutkan...";
                        cin.get();
                    } else {
                        cout << "Pilihan tidak valid! Silakan pilih 1-4.\n";
                    }
                } while (addChoice != 4);
                break;

            case 2: // Hapus Lagu
                cout << "\n--- Hapus Lagu Berdasarkan Judul ---\n";
                if (myPlaylist.isEmpty()) {
                    cout << "Playlist kosong! Tidak ada lagu yang bisa dihapus.\n";
                } else {
                    cout << "Masukkan judul lagu yang ingin dihapus: ";
                    getline(cin, title);
                    myPlaylist.removeByTitle(title);
                }
                break;

            case 3: // Tampilkan Playlist
                myPlaylist.displayAll();
                break;

            case 4: // Keluar
                cout << "\nTerima kasih telah menggunakan program Playlist!\n";
                break;

            default:
                cout << "Pilihan tidak valid! Silakan pilih 1-4.\n";
        }
    } while (choice != 4);

    return 0;
}