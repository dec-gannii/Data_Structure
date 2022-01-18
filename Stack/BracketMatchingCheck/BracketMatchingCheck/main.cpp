//
//  main.cpp
//  BracketMatchingCheck
//
//  Created by 김가은 on 2022/01/18.
//

/*
 이 프로그램에서는 작은 따옴표 내의 괄호도 일반적인 괄호로 생각하고 검사해서 조건 3의 위배 발생
 해당 내용 수정한 프로그램은 추후 보강 예정
 */

#include "ArrayStack.h"

bool CheckMatching( char* filename ) {
    // *fp가 가리키는 주소에 있는 데이터의 타입이 FILE 타입이므로 자료형을 FILE로 설정
    // fp는 반드시 포인터가 필요함. fopen 함수를 사용해서 읽기 모드(r)로 파일의 주소를 반환하기 때문에 fp는 포인터
    FILE *fp = fopen( filename, "r" );
    // 유효성 검사
    if( fp == NULL )
        error("Error: file not exists.\n");

    int nLine = 1; // 읽은 라인의 수
    int nChar = 0; // 읽은 문자 수
    
    ArrayStack stack; // ArrayStack 클래스 객체 stack
    char    ch; // char 형 변수

    // FILE이 끝나기 전까지 수행
    // 조건이 getc 함수를 통해 문자를 하나 가져와 ch에 저장하고 그 저장한 문자가 파일의 끝 문자인지 확인하고 아니라면 계속 반복
    // getc(fp) 함수는 파일 포인터가 가리킨 문자 하나를 읽어오는 함수
    while ( (ch = getc(fp)) != EOF ) {
        // 만약 읽어온 문자가 줄바꿈 문자라면 줄 수 하나 증가
        if( ch == '\n' ) nLine++;
        // 문자 하나 읽은 것이므로 문자 수 하나 증가
        nChar++;
        // 열린 괄호(왼쪽 괄호)면 스택에 삽입
        if( ch == '[' || ch == '(' || ch == '{' )
            stack.push(ch);
        // 닫는 괄호(오른쪽 괄호)면 prev 변수에 스택에서 삭제하고 반환한 요소 저장, 이후 짝 확인
        else if( ch == ']' || ch == ')' || ch == '}' ) {
            int prev = stack.pop();
            // 닫힌 괄호와 prev에 저장된 스택에서 꺼낸 가장 최근 삽입된 열린 괄호를 pop 한 것이 짝이 같지 않으면
            // 오류가 발생한 것이므로 break
            if( ( ch == ']' && prev != '[' )
                ||  ( ch == ')' && prev != '(' )
                ||  ( ch == '}' && prev != '{' ) ) break;
        }
    }
    
    fclose(fp); // 파일 닫기
    
    printf("[%s] file check result:\n", filename );
    
    // 스택이 공백이 아니라면 괄호의 개수 오류 (조건 1 위반) 발생
    if( !stack.isEmpty() )
        printf("  Error: bracket matching error! (line=%d, word=%d)\n\n", nLine,nChar );
    else
        printf("  OK: all bracket matches (line=%d, word=%d)\n\n", nLine,nChar);
    return stack.isEmpty();
}

// 파일 검사
int main()
{
    CheckMatching("ArrayStack.h");
    CheckMatching("main.cpp");
    
    return 0;
}
