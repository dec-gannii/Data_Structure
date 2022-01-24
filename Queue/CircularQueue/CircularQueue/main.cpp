//
//  main.cpp
//  CircularQueue
//
//  Created by 김가은 on 2022/01/24.
//

#include "CircularQueue.h"

int main(int argc, const char * argv[]) {
    CircularQueue que; // 원형 큐 객체 생성
    
    // 반복문을 사용해서 1부터 10까지의 수를 삽입
    for (int i = 1; i < 10; i++)
        que.enqueue(i);
    
    // 큐 내용 출력
    que.display();
    
    // 큐에서 앞에서 세 번째까지 입력된 값 삭제
    que.dequeue();
    que.dequeue();
    que.dequeue();
    // 1, 2, 3이 삭제되었을 것이라고 예측 가능
    // 이유는 큐가 FIFO 구조를 가지므로
    
    // 다시 큐 내용 출력
    que.display();
}
