#include <iostream>
using namespace std;

int queue[10];
int front = -1;
int rear = -1;

void enqueue(int idDokumen) {
    if (rear >= 9) {
        cout << "Antrian p
