//
//  ArrayStack.h
//  ArrayStack
//
//  Created by 김가은 on 2022/01/18.
//

#include <cstdio>
#include <cstdlib>

// 오류 처리 함수
inline void error(char *message) {
    printf("%s\n", message);
    exit(1);
}

// #define MAX_STACK_SIZE 20; 으로 사용해도 괜찮음 (상수 선언문)
const int MAX_STACK_SIZE = 20; // 스택의 최대 크기 설정

class ArrayStack {
    int top; // 요소의 개수
    int data[MAX_STACK_SIZE]; // 요소의 배열
    
    public:
    ArrayStack() {} // 스택 생성자
    ~ArrayStack() {} // 스택 소멸자
    bool isEmpty() { return top == -1; } // 공백 검사 함수 -> 공백 조건 : top == -1
    bool isFull() { return top == MAX_STACK_SIZE - 1; } // 포화 검사 함수 -> 포화 조건 : MAX_STACK_SIZE-1 (-1을 해주는 이유? 배열의 인덱스는 0부터 시작하므로)
    
    // 삽입 함수 (매개변수 : 삽입할 정수 요소)
    void push (int e) {
        // 맨 위에 항목 삽입
        // 포화 검사를 한 결과가 true이면, 오류 처리
        if (isFull()) error("stack is full!");
        // 아니라면 top을 하나 증가시킨 위치에 매개변수로 받은 요소를 저장
        data[++top] = e;
    }
    
    // 삭제 함수
    int pop() {
        // 맨 위의 요소를 삭제하고 반환
        // 공백 검사를 한 결과가 true이면, 오류 처리
        if (isEmpty()) error ("stack is empty!");
        // 아니라면 현재 top 위치의 값을 복사해놓은 후, top을 감소시키고, 복사해둔 값을 반환
        return data[top--];
    }
    
    // 최상위 검사
    int peek() {
        // 삭제하지 않고 요소 반환
        // 공백 검사를 한 결과가 true이면, 오류 처리
        if (isEmpty()) error("stack is empty!");
        // 아니라면, 현재 top 위치의 값을 반환
        return data[top];
    }
    
    // 출력 함수
    void display() {
        // 스택 내용을 화면에 출력
        printf("[stack element counts : %2d] ==> ", top+1);
        // 배열 인덱스가 0부터 시작하므로 top+1이 데이터의 개수
        
        // 반복문은 top+1번 반복
        for (int i = 0; i <= top; i++) {
            // 배열의 i번째에 있는 값을 출력
            printf("<%2d>", data[i]);
        }
        printf("\n");
    }
};
