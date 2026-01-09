#include <iostream>
#include "stack.h"
using namespace std;

void CreateStack(Stack &s) {
    s.top = -1;
}

void push(Stack &s, infotype x) {
    if (s.top < MAX - 1) {
        s.top++;
        s.info[s.top] = x;
    }
}

infotype pop(Stack &s) {
    infotype x = -1;
    if (s.top != -1) {
        x = s.info[s.top];
        s.top--;
    }
    return x;
}

void printInfo(Stack s) {
    cout << "[TOP] ";
    for (int i = s.top; i >= 0; i--) {
        cout << s.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &s) {
    int i = 0, j = s.top;
    while (i < j) {
        infotype temp = s.info[i];
        s.info[i] = s.info[j];
        s.info[j] = temp;
        i++; j--;
    }
}


void pushAscending(Stack &s, infotype x) {
    if (s.top == -1) {
        push(s, x);
        return;
    }

    Stack temp;
    CreateStack(temp);

    while (s.top != -1 && s.info[s.top] > x) {
        push(temp, pop(s));
    }

    push(s, x);

    while (temp.top != -1) {
        push(s, pop(temp));
    }
}
