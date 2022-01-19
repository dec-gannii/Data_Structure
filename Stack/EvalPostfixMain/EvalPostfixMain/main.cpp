//
//  main.cpp
//  EvalPostfixMain
//
//  Created by 김가은 on 2022/01/19.
//

#include "OperandStack.h"
#include <iostream>
using namespace std;

double calcPostfixExpr(FILE *fp = stdin) {
    char c; // 문자 변수
    OperandStack st; // 연산자 스택 객체
    
    while ((c=getc(fp)) != '\n') { // 엔터 치기 전까지의 문자를 계속해서 get 해옴
        // 가져온 문자가 연산자이면,
        if (c=='+' || c=='-' || c=='*' || c=='/') {
            // 두 번째 피연산자 먼저 pop()
            double val2 = st.pop();
            // 이어서 첫 번째 피연산자 pop()
            double val1 = st.pop();
            
            // c에 대한 switch문
            switch (c) {
                    // 연산자 각각에 따른 연산 수행, 결과를 스택에 다시 삽입
                case '+':
                    st.push(val1 + val2);
                    break;
                case '-':
                    st.push(val1 - val2);
                    break;
                case '*':
                    st.push(val1 * val2);
                    break;
                case '/':
                    st.push(val1 / val2);
                    break;
            }
        }
        // 문자에 해당하면 push()
        else if (c>='0' && c<='9') {
            // getc() 메소드로는 실수를 읽어들일 수 없으므로 ungetc() 수행
            ungetc(c, fp);
            // double 변수 val 선언 후
            double val;
            // fscanf로 다시 실수를 입력받음
            fscanf(fp, "%lf", &val);
            // 입력받은 실수를 스택에 push
            st.push(val);
        }
    }
    // 스택에 남아있는 요소를 pop()
    return st.pop();
}

int main(int argc, const char * argv[]) {
    printf("수식 입력 : (Postfix) = ");
    double res = calcPostfixExpr(); // Postfix 계산 결과를 double 변수 res에 저장
    printf("계산 결과 : %f\n", res); // 계산 결과 출력
}
