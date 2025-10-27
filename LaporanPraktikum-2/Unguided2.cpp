#include <iostream>
using namespace std;

int main() {
    int n;
    
    cout << "=== PROGRAM OPERASI ARRAY DENGAN POINTER ===\n";
    cout << "Masukkan jumlah elemen array (N): ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Jumlah elemen harus lebih dari 0!\n";
        return 1;
    }
    
    int *arr = new int[n];
    int *ptr = arr;
    
    cout << "\nMasukkan " << n << " elemen array:\n";
    for (int i = 0; i < n; i++) {
        cout << "Elemen ke-" << (i + 1) << ": ";
        cin >> *(ptr + i);
    }
    
    ptr = arr;
    
    int jumlah = 0;
    int maksimum = *ptr; 
    int minimum = *ptr; 
    
    for (int i = 0; i < n; i++) {
        jumlah += *(ptr + i);
        
        if (*(ptr + i) > maksimum) {
            maksimum = *(ptr + i);
        }
        
        if (*(ptr + i) < minimum) {
            minimum = *(ptr + i);
        }
    }
    
    cout << "\nArray yang diinput: ";
    for (int i = 0; i < n; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
    
    cout << "\nHASIL\n";
    cout << "Jumlah seluruh bilangan: " << jumlah << endl;
    cout << "Nilai maksimum: " << maksimum << endl;
    cout << "Nilai minimum: " << minimum << endl;
    
    delete[] arr;
    
    return 0;
}