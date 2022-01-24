//
//  CircularQueue.h
//  CircularQueue
//
//  Created by 김가은 on 2022/01/24.
//

#include <cstdio>
#include <cstdlib>

#define MAX_QUEUE_SIZE 100 // 상수 선언

// 오류 처리 함수
inline void error(char *message) {
    printf("%s\n", message);
    exit(1);
}

class CircularQueue {
protected:
    int front; // 첫 번째 요소 앞의 위치
    int rear; // 마지막 요소 위치
    int data[MAX_QUEUE_SIZE]; // 요소의 배열
    
public:
    // 생성자 - 초기 front, rear 값을 모두 0으로 초기화
    CircularQueue() { front = rear = 0; }
    
    // 공백 검사 - 조건 : front == rear
    bool isEmpty() { return front == rear; }
    
    // 포화 검사 - 조건 : front == (rear + 1) % MAX_QUEUE_SIZE -> 원형제어를 하기 위해 사용하는 식
    bool isFull() { return (rear + 1) % MAX_QUEUE_SIZE == front; }
    
    // 삽입 함수
    void enqueue( int val ) { // 큐에 삽입
        // 포화 검사 시 포화 상태면 오류 발생
        if (isFull()) { error("error : Queue is Full!\n"); }
        else {
            // 포화 상태가 아니라면 rear 위치를 다음 위치로 바꾸고 입력할 값을 해당 위치에 저장
            rear = (rear + 1) % MAX_QUEUE_SIZE; // 원형 제어문
            data[rear] = val;
        }
    }
    
    // 삭제 함수
    int dequeue() { // 큐에서 삭제
        // 공백 검사 시 공백 상태면 오류 발생
        if (isEmpty()) { error("error : Queue is Empty!\n"); }
        else {
            // 공백 상태가 아니라면 front 위치를 다음 위치로 바꾸고 삭제할 값을 삭제 및 반환
            front = (front + 1) % MAX_QUEUE_SIZE; // 원형 제어문
            return data[front];
        }
        return 0;
    }
    
    // 최상단 검사
    int peek() { // 첫 항목을 큐에서 삭제하지 않고 반환
        // 공백 검사 시 공백 상태면 오류 발생
        if (isEmpty()) { error("error : Queue is Empty!\n"); }
        // 공백 상태 아니라면 front의 위치는 변화하지 않고 front + 1의 위치에 있는 값 반환
        else return data[(front + 1) % MAX_QUEUE_SIZE];
        
        return 0;
    }
    
    // 출력 함수
    void display() {
        printf("Queue : ");
        // 최대 인덱스를 구하기
        // 삼항 연산자 사용 -> (조건)이 참이면 (조건) ? A : B 에서 A를 할당, 거짓이면 B를 대입
        int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
        for (int i = front + 1; i <= maxi; i++)
            printf("[%2d] ", data[i%MAX_QUEUE_SIZE]);
        printf("\n");
    }
};
