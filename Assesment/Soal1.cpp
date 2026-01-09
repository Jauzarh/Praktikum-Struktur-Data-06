#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node* prev;
};

Node* head = NULL;

void tambahLaguDiAwal(string judulLagu) {
    // Buat node baru
    Node* baru = new Node;
    baru->data = judulLagu;
    baru->next = NULL;
    baru->prev = NULL;

    // Jika list masih kosong
    if (head == NULL) {
        head = baru;
    } else {
        // Hubungkan node baru dengan head lama
        baru->next = head;
        head->prev = baru;

        // Jadikan node baru sebagai head
        head = baru;
    }

    cout << "Lagu '" << judulLagu << "' ditambahkan ke awal playlist." << endl;
}

void tampil() {
    if (head == NULL) {
        cout << "Playlist kosong." << endl;
        return;
    }

    cout << "\nDaftar Playlist:\n";

    Node* temp = head;
    while (temp != NULL) {
        cout << "- " << temp->data << endl;
        temp = temp->next;
    }
}

int main() {
    tambahLaguDiAwal("Melukis Senja - Budi Doremi");
    tambahLaguDiAwal("Halu - Feby Putri");

    tampil();

    return 0;
}
