//
//  main.cpp
//  Infix2Postfix
//
//  Created by 김가은 on 2022/01/19.
//

#include "ArrayStack.h"

inline int    precedence( char op )
{
    switch (op) {
        case '(' : case ')' : return 0;
        case '+' : case '-' : return 1;
        case '*' : case '/' : return 2;
    }
    return -1;
}

void infix2Postfix( FILE *fp = stdin )
{
    char        c, op;
    double        val;
    ArrayStack    st;

    while ( (c=getc(fp)) != '\n' ) {

        if ((c>='0' && c<='9')) {
            ungetc( c, fp );
            fscanf( fp, "%lf", &val );

            printf("%4.1f ", val);
        }

        else if( c=='(' )
            st.push( c );


        else if( c==')' ) {
            while (!st.isEmpty()) {
                op = st.pop();
                if( op== '(' ) break;
                else printf( "%c ", op );
            }
        }

        else if( c=='+' || c=='-' || c=='*' || c=='/' ){
            while ( !st.isEmpty() ) {
                op = st.peek();
                if ( precedence(c) <= precedence(op) ) {
                    printf( "%c ", op );
                    st.pop();
                }
                else break;
            }
            st.push( c );
        }
    }
    while (!st.isEmpty())
        printf( "%c ", st.pop() );
}


int main()
{
    printf("수식 입력 (Infix) = ");
    infix2Postfix( );
}
