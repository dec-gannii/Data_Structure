//
//  Polynomial.h
//  Polynomial
//
//  Created by 김가은 on 2022/01/17.
//

#include <cstdio>
#define MAX_DEGREE 80 // 다항식의 처리 가능한 최대 차수 + 1
class Polynomial {
    int degree; // 다항식의 최고 차수
    float coef[MAX_DEGREE]; // 각 항에 대한 계수
    
public:
    Polynomial() { degree = 0; } // 생성자 : 최대 차수를 0으로 초기화
    
    // 다항식의 내용을 입력받는 멤버 함수
    void read() { // 다항식의 내용 입력
        printf("다항식의 최고 차수를 입력하시오 : ");
        scanf("%d", &degree); // &degree에 해당하는 주소에 저장
        printf("각 항의 계수를 입력하시오. (총 %d개) : ", degree + 1);
        // degree+1인 이유는 상수항을 포함하기 때문 -> 총 필요한 항의 계수의 갯수는 차수 + 1에 해당
        for ( int i = 0; i <= degree; i++ ) {
            scanf("%f", coef+i); // 배열의 순서를 증가시켜가며 해당하는 위치에 저장
        }
    }
    
    // 다항식의 내용을 화면에 출력하는 함수
    void display(char *str=" Poly = ") { // "Poly = "는 디폴트 매개변수에 해당
        printf("\t%s", str);
        for ( int i = 0; i < degree; i++ ) {
            printf("%5.1f x^%d + ", coef[i], degree - i);
            // coef[i] : 계수
            // degree - i : 차수
        }
        printf( "%4.1f\n", coef[degree] ); // coef[degree] : 최고차항의 계수에 해당
    }
    
    /*
     디폴트 매개변수란?
     매개변수를 받지 않은 경우 기본적으로 지정되는 매개변수
     */
    
    // 다항식 a와 b를 더하는 함수. a와 b를 더해서 자신의 다항식을 설정
    // 매개변수로 Polynomial 객체를 받음
    void add(Polynomial a, Polynomial b) {
        if (a.degree > b.degree) { // 다항식 a의 항 > 다항식 b의 항
            *this = a; // a 다항식을 자기 객체에 복사
            for ( int i = 0; i <= b.degree; i++ ) { // b의 차수만큼 반복
                coef[i+(degree-b.degree)] += b.coef[i];
                // degree - b.degree : 차수의 차이
                // b.coef[i] : b의 최고차항에서부터 i번째 항의 계수
            }
        } else { // 다항식 a의 항 < 다항식 b의 항
            *this = b; // b 다항식을 자기 객체에 복사
            for ( int i = 0; i <= a.degree; i++ ) { // a의 차수만큼 반복
                coef[i+(degree - a.degree)] += a.coef[i];
                // degree - a.degree : 차수의 차이
                // a.coef[i] : a의 최고차항에서부터 i번째 항의 계수
            }
        }
    }
    /*
     b.degree - a.degree 또는 a.degree - b.degree는 결과 다항식의 최대 차수가 됨
     */
    
    // 최고차수가 0인가?
    bool isZero() {
        return degree == 0;
    }
    
    // 모든 계수의 부호를 바꿔줌
    void negate() {
        for ( int i = 0; i <= degree; i++ ) {
            coef[i] = -coef[i]; // 부호 변경
        }
    }
};


