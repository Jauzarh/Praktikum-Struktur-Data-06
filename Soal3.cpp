#include <iostream>
using namespace std;

int main() {
    int n;
    
    cout << "Input: ";
    cin >> n;
    
    cout << "Output:" << endl;
    
    for (int i = n; i >= 0; i--) {
        // Bagian kiri (angka menurun)
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        
        // Bagian tengah (bintang)
        if (i > 0) {
            cout << "* ";
        } else {
            cout << "*";
        }
        
        // Bagian kanan (angka naik)
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
    
    return 0;
}