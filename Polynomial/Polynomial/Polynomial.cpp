//
//  Polynomial.cpp
//  Polynomial
//
//  Created by 김가은 on 2022/01/17.
//

#include "Polynomial.h"

int main() {
    Polynomial a, b, c;
    a.read();
    b.read();
    c.add(a, b);
    a.display("A = ");
    b.display("B = ");
    c.display("A + B = ");
    return 0;
}
