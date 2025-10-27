#include <iostream>
using namespace std;

// Fungsi untuk menghitung rata-rata
float hitungRataRata(int arr[], int n) {
    float total = 0;
    for(int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total / n;
}

// Fungsi untuk mencari nilai maksimum dan minimum
void cariMaxMin(int arr[], int n, int &maks, int &min) {
    maks = arr[0];
    min = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > maks) maks = arr[i];
        if(arr[i] < min) min = arr[i];
    }
}

int main() {
    int N;
    cout << "Masukkan jumlah siswa: ";
    cin >> N;

    int nilai[N];
    cout << "Masukkan nilai ujian untuk " << N << " siswa:\n";
    for(int i = 0; i < N; i++) {
        cin >> nilai[i];
    }

    float rata = hitungRataRata(nilai, N);
    int maksimum, minimum;
    cariMaxMin(nilai, N, maksimum, minimum);

    cout << "Nilai rata-rata kelas : " << rata << endl;
    cout << "Nilai tertinggi       : " << maksimum << endl;
    cout << "Nilai terendah        : " << minimum << endl;
    return 0;
}
