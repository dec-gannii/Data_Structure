//
//  Polynomial.cpp
//  Polynomial
//
//  Created by 김가은 on 2022/01/17.
//

#include "Polynomial.h"

int main() {
    Polynomial a, b, c; // 다항식 객체 a, b, c를 생성
    a.read(); // 다항식 a의 차수와 각 차수에 따른 계수를 받아옴
    b.read(); // 다항식 b의 차수와 각 차수에 따른 계수를 받아옴
    c.add(a, b); // 다항식 a와 b를 더하는 연산 수행
    a.display("A = "); // 다항식 a의 내용을 화면에 출력
    b.display("B = "); // 다항식 b의 내용을 화면에 출력
    c.display("A + B = ");  // 다항식 c(다항식 a와 다항식 b의 합)의 내용을 화면에 출력
    return 0;
}
