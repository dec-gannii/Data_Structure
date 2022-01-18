//
//  main.cpp
//  StudentStack
//
//  Created by 김가은 on 2022/01/18.
//

#include "StudentStack.h"

int main(int argc, const char * argv[]) {
    StudentStack stack;
    
    // 세 명의 학생을 스택에 삽입
    stack.push(Student(2015130007, "홍길동", "컴퓨터공학과"));
    stack.push(Student(2015130100, "이순신", "기계공학과"));
    stack.push(Student(2015130135, "황희", "법학과"));
    // 스택의 현재 상태 출력
    stack.display();
    // 스택에서 요소 하나를 삭제
    stack.pop();
    // 가장 마지막에 삽입된 요소인 <2015130135, "황희", "법학과">가 삭제되어 출력될 것이라고 예측 가능
    // 스택의 현재 상태 출력
    stack.display();
    
    return 0;
}
