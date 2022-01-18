//
//  main.cpp
//  ArrayStack
//
//  Created by 김가은 on 2022/01/18.
//

#include "ArrayStack.h" // ArrayStack 클래스를 포함

int main(int argc, const char * argv[]) {
    // 묵시적 객체 생성 방법으로 ArrayStack 객체 생성
    ArrayStack stack; // ArrayStack은 클래스, stack은 ArrayStack 클래스 객체의 이름
    
    for (int i = 0; i < 10; i++) {
        stack.push( i ); // 1부터 9까지의 숫자를 push 함수의 매개변수로 전달해 stack에 삽입
    }
    
    stack.display(); // 현재 스택의 요소들을 출력
    stack.pop(); // 스택에서 하나 삭제
    stack.pop(); // 스택에서 하나 삭제
    stack.pop();// 스택에서 하나 삭제
    // ==> 스택에 가장 나중에 들어간 총 세 개의 요소(7, 8, 9)가 삭제되었을 것임을 예측 가능
    stack.display(); //현재 스택의 요소들을 출력
    
    return 0;
}
