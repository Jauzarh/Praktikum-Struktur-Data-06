#ifndef STACK_H
#define STACK_H

#define MAX 20
typedef int infotype;

struct Stack {
    infotype info[MAX];
    int top;
};

void CreateStack(Stack &s);
void push(Stack &s, infotype x);
infotype pop(Stack &s);
void printInfo(Stack s);
void balikStack(Stack &s);

/* TAMBAHAN */
void pushAscending(Stack &s, infotype x);

#endif
