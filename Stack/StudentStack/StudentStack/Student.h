//
//  Student.h: 학생 정보를 나타내는 클래스
//  StudentStack
//
//  Created by 김가은 on 2022/01/18.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX_STRING 100

class Student {
    int id; // 학번
    char name[MAX_STRING]; // 이름
    char dept[MAX_STRING]; // 소속학과
    
public:
    // 생성자 : 디폴트 매개변수 사용, 매개변수를 set 함수의 매개변수로 전달
    Student (int i = 0, char* n="", char* d="") { set( i, n, d ); }
    
    // 학번, 이름, 학과를 설정하는 함수
    void set (int i, char* n, char* d) {
        // 매개변수로 받아온 것들을 각각 id, name, dept 변수에 저장
        id = i;
        // strcpy : 문자열 복사 함수
        strcpy(name, n);
        strcpy(dept, d);
    }
    
    // 학번, 이름, 학과를 출력하는 함수
    void display() {
        printf("studentID : %-15d name : %-10s department: %-20s\n", id, name, dept);
    }
};

