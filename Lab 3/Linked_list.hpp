//
//  Linked_list.hpp
//  Lab 3
//
//  Created by Fredrik Sellgren on 2018-05-02.
//  Copyright © 2018 Fredrik Sellgren. All rights reserved.
//

#ifndef Linked_list_hpp
#define Linked_list_hpp
#include <iostream>
#include <stdio.h>
class linked_list{
public:
    linked_list() = default;
   /**/ linked_list(const linked_list& src);
    
  /**/  ~linked_list();
    
    /**/ linked_list& operator=(const linked_list& rhs);
    
    // adds elements to the back.
   /**/ linked_list& operator+=(const linked_list& rhs);
    
    // inserting elements
    void insert(double value , size_t pos);
    // in front
  /**/ void push_front(double value);
    // in back
  /**/  void push_back(double value);
    
    
    // accessing elements
    /**/ double front() const;
   /**/ double back() const;
    /**/ double at(size_t pos) const;
    
    // removing elements
    void remove (size_t pos);
    
    // remove and access
   /**/ double pop_front();
   /**/ double pop_back();
    
    // informational
    /**/size_t size() const;
    /**/bool is_empty() const;
    
    // output
   /**/ void print() const;
   /**/ void print_reverse() const;
    
    //merge
    linked_list merge(linked_list list1, linked_list list2);
    
    bool isSorted() const;
    
private: struct node_t{
    node_t(double value, node_t* next=0, node_t* prev=0)
    : value(value),next(next),prev(prev){}
    double value;
    node_t* next;
    node_t* prev;
};
    node_t* head = nullptr;
    node_t* tail = nullptr;
};


#endif /* Linked_list_hpp */
