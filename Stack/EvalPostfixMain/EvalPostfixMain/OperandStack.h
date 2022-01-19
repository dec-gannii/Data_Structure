//
//  OperandStack.h
//  EvalPostfixMain
//
//  Created by 김가은 on 2022/01/19.
//

#include <cstdio>
#include <cstdlib>
const int MAX_STACK_SIZE = 100;

inline void error (char *message) {
    printf("%s\n", message);
    exit(1);
}

class OperandStack {
    double data[MAX_STACK_SIZE];
    int top;
public:
    OperandStack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX_STACK_SIZE - 1 ; }
    
    void push(double e) {
        if (isFull()) {
            error("stack is full!");
        }
        data[++top] = e;
    }
   
    double pop() {
        if (isEmpty()) {
            error("stack is empty!");
        }
        return data[top--];
    }
};
