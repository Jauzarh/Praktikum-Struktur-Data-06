#include <iostream>
using namespace std;

int main() {
    float bilangan1, bilangan2;
    
    cin >> bilangan1;
    cin >> bilangan2;
    
    float penjumlahan = bilangan1 + bilangan2;
    float pengurangan = bilangan1 - bilangan2;
    float perkalian = bilangan1 * bilangan2;
    
    cout << "\nHasil operasi:" << endl;
    cout << "Penjumlahan: " << bilangan1 << " + " << bilangan2 << " = " << penjumlahan << endl;
    cout << "Pengurangan: " << bilangan1 << " - " << bilangan2 << " = " << pengurangan << endl;
    cout << "Perkalian: " << bilangan1 << " * " << bilangan2 << " = " << perkalian << endl;
    
    if (bilangan2 != 0) {
        float pembagian = bilangan1 / bilangan2;
        cout << "Pembagian: " << bilangan1 << " / " << bilangan2 << " = " << pembagian << endl;
    } else {
        cout << "Pembagian: " << bilangan1 << " / " << bilangan2 << " = Tidak dapat membagi dengan nol" << endl;
    }
    
    return 0;
}