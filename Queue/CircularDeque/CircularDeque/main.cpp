//
//  CircularDeque.cpp
//  CircularDeque
//
//  Created by 김가은 on 2022/01/24.
//

#include "CircularDeque.h"

int main() {
    CircularDeque deq;
    
    for (int i = 1; i < 10; i++){
        if (i % 2 == 1) deq.addFront( i );
        else deq.addRear( i );
    }
    
    deq.display();
    deq.deleteFront();
    deq.deleteRear();
    deq.deleteFront();
    deq.display();
}
