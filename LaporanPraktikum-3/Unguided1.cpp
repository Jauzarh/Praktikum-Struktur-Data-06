#include <iostream>
using namespace std;

int queue[10];
int front = -1;
int rear = -1;

void enqueue(int idDokumen) {
    if (rear >= 9) {
        cout << "Antrian penuh!" << endl;
        return;
    }
    
    if (front == -1) {
        // [1] Jika antrian awal, set front jadi 0
        front = 0;
    }
    
    // [2] Naikkan rear
    rear++;
    
    // [3] Masukkan idDokumen ke array queue di posisi rear
    queue[rear] = idDokumen;
    
    cout << "Dokumen " << idDokumen << " masuk antrian." << endl;
}

int dequeue() {
    if (front == -1 || front > rear) {
        cout << "Antrian kosong!" << endl;
        return -1;
    }
    
    int dokumenKeluar = queue[front];
    
    // [4] Geser front maju
    front++;

    return dokumenKeluar;
}

int main() {
    enqueue(1);
    enqueue(2);
    
    cout << "Mencetak: " << dequeue() << endl;
    
    enqueue(3);
    
    cout << "Mencetak: " << dequeue() << endl;
    cout << "Mencetak: " << dequeue() << endl;
    return 0;
}
