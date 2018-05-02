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
    linked_list ll1;
    linked_list ll2;
    
    
    //Fyller två länkade listor med 100 tal.
    for (int i = 0; i < 100; i++) {
        ll1.push_back( ll1.back() + rand()% 20);
        ll2.push_back(ll2.back() + rand()% 20);
    }
    
    //Kollar vilken av de länkade listorna som har störst värde och tar sedan bort det största
    if( ll1.operator[](50) > ll2.operator[](50) ){
        std::cout << "First list holds the bigger value" << std::endl;
        ll1.remove(50);
    }
    else if ( ll1.operator[](50) == ll2.operator[](50) )
    {
        std::cout << "Both values in the list are equals" << std::endl;
    }
    else
    {
        std::cout << "First list holds the bigger value" << std::endl;
        ll2.remove(50);
    }
    
    // Operator = Deklarera en tredje lista. Tilldela därefter lista 1 till den tredje listan.
    linked_list ll3;
    ll3 = ll1;
    
    //pop_back, push_front Ta bort varannat element genom att iterera
    for(int i = 0; i < 50; i++)
    {
        ll3.pop_back();
        ll3.push_front(ll3.pop_back());
    }
    
    //print Skapa och anropa en global funktion
    //ll3.print();
    
    //Skapa en fjärde lista. Lista ut en metod som kombinerar lista 1 och 2 till den fjärde listan så att den fjärdes element ligger i ordning.
    
    linked_list ll4;
    
    ll4.merge(ll1, ll2);

    ll4.print();

    return 0;
}
