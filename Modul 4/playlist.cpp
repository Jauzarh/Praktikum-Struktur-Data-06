#include "playlist.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Implementasi kelas Song
Song::Song(string t, string a, float d) 
    : title(t), artist(a), duration(d), next(nullptr) {}

// Implementasi kelas Playlist
Playlist::Playlist() : head(nullptr), count(0) {}

Playlist::~Playlist() {
    while (!isEmpty()) {
        removeByTitle(head->title);
    }
}

void Playlist::addFirst(string title, string artist, float duration) {
    Song* newSong = new Song(title, artist, duration);
    newSong->next = head;
    head = newSong;
    count++;
    cout << "Lagu \"" << title << "\" berhasil ditambahkan di awal playlist.\n";
}

void Playlist::addLast(string title, string artist, float duration) {
    Song* newSong = new Song(title, artist, duration);
    
    if (isEmpty()) {
        head = newSong;
    } else {
        Song* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newSong;
    }
    count++;
    cout << "Lagu \"" << title << "\" berhasil ditambahkan di akhir playlist.\n";
}

void Playlist::addAfterThird(string title, string artist, float duration) {
    if (count < 3) {
        cout << "Playlist belum memiliki 3 lagu. Menambahkan di akhir...\n";
        addLast(title, artist, duration);
        return;
    }

    Song* newSong = new Song(title, artist, duration);
    Song* current = head;
    
    // Mencari lagu ketiga
    for (int i = 1; i < 3; i++) {
        current = current->next;
    }
    
    newSong->next = current->next;
    current->next = newSong;
    count++;
    cout << "Lagu \"" << title << "\" berhasil ditambahkan setelah lagu ke-3.\n";
}

bool Playlist::removeByTitle(string title) {
    if (isEmpty()) {
        cout << "Playlist kosong! Tidak ada lagu yang bisa dihapus.\n";
        return false;
    }

    Song* current = head;
    Song* previous = nullptr;

    // Jika head yang akan dihapus
    if (current != nullptr && current->title == title) {
        head = current->next;
        cout << "Lagu \"" << current->title << "\" berhasil dihapus.\n";
        delete current;
        count--;
        return true;
    }

    // Mencari lagu dengan judul yang sesuai
    while (current != nullptr && current->title != title) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Lagu dengan judul \"" << title << "\" tidak ditemukan.\n";
        return false;
    }

    // Menghapus node
    previous->next = current->next;
    cout << "Lagu \"" << current->title << "\" berhasil dihapus.\n";
    delete current;
    count--;
    return true;
}

void Playlist::displayAll() {
    if (isEmpty()) {
        cout << "\nPlaylist kosong!\n";
        return;
    }

    cout << "\n=== DAFTAR LAGU DALAM PLAYLIST ===\n";
    cout << "Jumlah lagu: " << count << "\n\n";
    
    cout << left << setw(4) << "No." 
         << setw(25) << "Judul Lagu" 
         << setw(20) << "Penyanyi" 
         << setw(10) << "Durasi" 
         << endl;
    cout << string(60, '-') << endl;

    Song* current = head;
    int index = 1;
    
    while (current != nullptr) {
        cout << left << setw(4) << index 
             << setw(25) << current->title.substr(0, 24) 
             << setw(20) << current->artist.substr(0, 19)
             << fixed << setprecision(2) << current->duration << " menit" 
             << endl;
        current = current->next;
        index++;
    }
    cout << endl;
}

int Playlist::getCount() {
    return count;
}

bool Playlist::isEmpty() {
    return head == nullptr;
}