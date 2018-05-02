//
//  Linked_list.cpp
//  Lab 3
//
//  Created by Fredrik Sellgren on 2018-05-02.
//  Copyright © 2018 Fredrik Sellgren. All rights reserved.
//

#include "Linked_list.hpp"
//Constructor
linked_list::linked_list(const linked_list& src)
{
    *this = src;
}
//Destructor som förstör element
linked_list::~linked_list()
{
    node_t* iterator = head;
    while (iterator) {
        node_t *next = iterator->next;
        delete iterator;
        iterator = next;
        //std::cout << "I Killed a element " << std::endl;
    }
}

linked_list& linked_list::operator=(const linked_list& rhs)
{
    node_t* iterator = rhs.head;
    if(this == &rhs)
        return *this;
    while(!is_empty()) pop_back();
    while (iterator) {
        push_back(iterator->value);
        iterator = iterator->next;
    }
    return *this;
}

linked_list& linked_list::operator+=(const linked_list& rhs)
{
    node_t* iterator = rhs.head;
    while (iterator) {
        push_back(iterator->value);
        iterator = iterator->next;
    }
    
    return *this;
}

// inserting elements
void linked_list::push_back(double value)
{
    if (!(head && tail)) {
       node_t* tmp = new node_t(value);
        head = tail = tmp;
    }else
    {
        node_t* tmp = new node_t(value);
        tail->next = tmp;
        tmp->prev = tail;
        tail = tmp;
    }
}

void linked_list::push_front(double value)
{
    if(!(head && tail)){
        node_t* tmp = new node_t(value);
        head = tail = tmp;
    }else
    {
        node_t* tmp = new node_t(value);
        head->prev = tmp;
        tmp->next = head;
        head = tmp;
    }
    
}

// remove and access
double linked_list::pop_back()
{
    double value;
   node_t* tmp = tail->prev;
    if(tmp)
    {
        tmp->next = nullptr;
        value=tail->value;
        delete tail;
        tail = tmp;
    }else
    {
        value = tail->value;
        delete tail;
        head = tail = nullptr;
        
    }
    
    return value;
}

double linked_list::pop_front()
{
    double value;
    node_t* tmp = head->next;
    if(tmp)
    {
        tmp->prev = nullptr;
        value = head->value;
        delete head;
        head = tmp;
    }else
    {
        value = head->value;
        delete head;
        head = tail = nullptr;
    }
    return value;
}

// accessing elements
double linked_list::front() const
{
    return head->value;
}

double linked_list::back() const
{
    return tail->value;
}

double & linked_list::operator[](size_t pos)
{
    node_t *iterator = head;
    for (size_t i = 0; i < pos; i++) {
        iterator = iterator->next;
    }
    
    return iterator->value;
}

// informational
bool linked_list::is_empty() const
{
    return head == nullptr;
}

size_t linked_list::size() const
{
    size_t count = 0;
    node_t* iterator = head;
    while(iterator)
    {
        iterator = iterator->next;
        ++count;
    }
    return count;
}

// output
void linked_list::print() const
{
    node_t* iterator = head;
    while (iterator) {
        std::cout << iterator->value << "\n";
        iterator = iterator->next;
    }
}

void linked_list::print_reverse() const
{
    node_t* iterator = tail;
    while (iterator) {
        std::cout << iterator->value << "\n";
        iterator = iterator->prev;
    }
}
