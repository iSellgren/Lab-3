//
//  main.cpp
//  Lab 3
//
//  Created by Fredrik Sellgren on 2018-05-01.
//  Copyright © 2018 Fredrik Sellgren. All rights reserved.
//

#include "Linked_list.hpp"
#include <stdio.h>
#include <stdlib.h>

int main() {
    linked_list ll;
    linked_list test;
    for (int i = 0; i < 10; i++) {
        ll.push_front(i);
    }
    linked_list temp(ll);
    temp.print();
    std::cout << ll.size() << std::endl;

    return 0;
}
