#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    const int JUMLAH_MAHASISWA = 5;
    const int JUMLAH_MATA_KULIAH = 3;
    
    string nama[JUMLAH_MAHASISWA];
    double nilai[JUMLAH_MAHASISWA][JUMLAH_MATA_KULIAH];
    double rataRata[JUMLAH_MAHASISWA];
    
    cout << "=== PROGRAM NILAI MAHASISWA ===\n";
    for (int i = 0; i < JUMLAH_MAHASISWA; i++) {
        cout << "\nMahasiswa ke-" << (i + 1) << ":\n";
        cout << "Nama: ";
        cin.ignore();
        getline(cin, nama[i]);
        
        for (int j = 0; j < JUMLAH_MATA_KULIAH; j++) {
            cout << "Nilai mata kuliah " << (j + 1) << ": ";
            cin >> nilai[i][j];
        }
    }
    
    for (int i = 0; i < JUMLAH_MAHASISWA; i++) {
        double total = 0;
        for (int j = 0; j < JUMLAH_MATA_KULIAH; j++) {
            total += nilai[i][j];
        }
        rataRata[i] = total / JUMLAH_MATA_KULIAH;
    }
    
    int indeksTerbaik = 0;
    for (int i = 1; i < JUMLAH_MAHASISWA; i++) {
        if (rataRata[i] > rataRata[indeksTerbaik]) {
            indeksTerbaik = i;
        }
    }
    
    // menampilkan tabel
    cout << "\n=== HASIL NILAI MAHASISWA ===\n";
    cout << "=====================================================================\n";
    cout << left << setw(15) << "Nama" 
         << setw(12) << "Mata Kuliah 1" 
         << setw(12) << "Mata Kuliah 2" 
         << setw(12) << "Mata Kuliah 3" 
         << setw(10) << "Rata-rata" 
         << setw(10) << "Keterangan" << endl;
    cout << "=====================================================================\n";
    
    for (int i = 0; i < JUMLAH_MAHASISWA; i++) {
        cout << left << setw(15) << nama[i];
        for (int j = 0; j < JUMLAH_MATA_KULIAH; j++) {
            cout << setw(12) << fixed << setprecision(1) << nilai[i][j];
        }
        cout << setw(10) << fixed << setprecision(2) << rataRata[i];
        
        if (i == indeksTerbaik) {
            cout << "TERBAIK";
        }
        cout << endl;
    }
    cout << "=====================================================================\n";
    
    cout << "\nMahasiswa terbaik: " << nama[indeksTerbaik] 
         << " dengan rata-rata: " << fixed << setprecision(2) << rataRata[indeksTerbaik] << endl;
    
    return 0;
}