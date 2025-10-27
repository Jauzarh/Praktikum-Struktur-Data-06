#include <iostream>
using namespace std;

int main() {
    int angka;
    
    cin >> angka;
    
    if (angka < 0 || angka > 100) {
        cout << "Angka di luar range (0-100)" << endl;
        return 1;
    }
    
    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", 
                       "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", 
                       "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};
    
    string hasil;
    
    if (angka == 0) {
        hasil = "nol";
    }
    else if (angka == 100) {
        hasil = "seratus";
    }
    else if (angka >= 1 && angka <= 9) {
        hasil = satuan[angka];
    }
    else if (angka >= 10 && angka <= 19) {
        hasil = belasan[angka - 10];
    }
    else {
        int puluh = angka / 10;
        int satu = angka % 10;
        
        if (satu == 0) {
            hasil = puluhan[puluh];
        } else {
            hasil = puluhan[puluh] + " " + satuan[satu];
        }
    }
    
    cout << angka << " : " << hasil << endl;
    
    return 0;
}