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
        scanf("%d", &degree);
        printf("각 항의 계수를 입력하시오. (총 %d개) : ", degree + 1);
        for ( int i = 0; i <= degree; i++ ) {
            scanf("%f", coef+i);
        }
    }
    
    void display(char *str=" Poly = ") {
        printf("\t%s", str);
        for ( int i = 0; i < degree; i++ ) {
            printf("%5.1f x^%d + ", coef[i], degree - i);
        }
        printf( "%4.1f\n", coef[degree] );
    }
    
    void add(Polynomial a, Polynomial b) {
        if (a.degree > b.degree) {
            *this = a;
            for ( int i = 0; i <= b.degree; i++ ) {
                coef[i+(degree-b.degree)] += b.coef[i];
            }
        } else {
            *this = b;
            for ( int i = 0; i <= a.degree; i++ ) {
                coef[i+(degree - a.degree)] += a.coef[i];
            }
        }
    }
    
    bool isZero() {
        return degree == 0;
    }
    
    void negate() {
        for ( int i = 0; i <= degree; i++ ) {
            coef[i] = -coef[i];
        }
    }
};


