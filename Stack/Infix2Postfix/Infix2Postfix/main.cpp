//
//  main.cpp
//  Infix2Postfix
//
//  Created by 김가은 on 2022/01/19.
//

#include "ArrayStack.h"

// 객체의 우선순위 계산
inline int    precedence( char op )
{
    switch (op) {
        case '(' : case ')' : return 0; // 괄호는 우선순위가 최하
        case '+' : case '-' : return 1; // 중간 우선순위
        case '*' : case '/' : return 2; // 최고 우선순위
    }
    return -1; // 나머지는 종료
}

// 중위 표기 수식을 후위 표기 수식으로 변환하는 메소드
void infix2Postfix( FILE *fp = stdin ) // 키보드 입력을 통해 수식 입력 받기
{
    // 변수 및 스택 객체 선언
    char        c, op;
    double        val;
    ArrayStack    st;
    
    // fp가 가리키는 하나의 문자를 가지고 온 것이 줄바꿈 문자가 아닌 동안 계속 해서 반복
    while ( (c=getc(fp)) != '\n' ) {
        // 피연산자에 해당하는 문자이면
        if ((c>='0' && c<='9')) {
            ungetc( c, fp ); // getc()로는 실수 가져오기 불가능하므로 ungetc() 수행
            fscanf( fp, "%lf", &val ); // fscanf로 다시 실수 입력 받기
            
            printf("%4.1f ", val); // 입력받은 실수 출력
        }
        
        else if( c=='(' ) // 입력받은 문자가 열린 괄호(왼쪽 괄호)이면,
            st.push( c ); // 스택에 삽입
        else if( c==')' ) { // 입력받은 문자가 닫힘 괄호(오른쪽 괄호)이면,
            while (!st.isEmpty()) { // 스택이 비어있지 않은 동안 반복
                op = st.pop(); // 스택에서 pop해서 변수 op에 저장
                if( op== '(' ) break; // 만약 pop한 요소가 열린 괄호(왼쪽 괄호)이면, break
                else printf( "%c ", op ); // 아니면 계속해서 출력
            }
        }
        
        else if( c=='+' || c=='-' || c=='*' || c=='/' ){ // 입력받은 문자가 연산자이면,
            while ( !st.isEmpty() ) { // 스택이 비어있지 않은 동안 반복
                op = st.peek(); // 스택의 최상위 요소를 가져옴
                if ( precedence(c) <= precedence(op) ) { // 가져온 최상위 요소와 입력받은 연산자의 우선순위 비교
                    // 입력받은 문자의 우선순위가 op의 우선순위보다 낮거나 같으면
                    printf( "%c ", op ); // op 출력
                    st.pop(); // 스택에서 pop
                }
                else break; // 아닌 경우 break
            }
            st.push( c ); // 스택에 입력받은 연산자 삽입
        }
    }
    while (!st.isEmpty()) // 스택이 비어있지 않은 동안 반복
        printf( "%c ", st.pop() ); // 스택에 있는 요소를 pop해서 출력
}


int main()
{
    printf("수식 입력 (Infix) = ");
    infix2Postfix( ); // 수식 계산 함수 수행
}
