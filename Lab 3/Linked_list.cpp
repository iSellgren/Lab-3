//
//  Linked_list.cpp
//  Lab 3
//
//  Created by Fredrik Sellgren on 2018-05-02.
//  Copyright © 2018 Fredrik Sellgren. All rights reserved.
//

#include "Linked_list.hpp"
using namespace std;
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
        //std::cout << "Siri Killed a element " << std::endl;
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
    return *this; //return *this -> return värdet by reference
}

linked_list& linked_list::operator+=(const linked_list& rhs)
{
    node_t* iterator = rhs.head;
    while (iterator) { //
        push_back(iterator->value); // bygger ut listan med den andra listan.
        iterator = iterator->next;
    }
    
    return *this; //return *this -> return värdet by reference
}

// inserting elements

void linked_list::insert(double value, size_t pos)
{
    
    node_t *NewNode = new node_t(value);
    node_t *temp;
    NewNode->value = value;
    
    if (head != NULL)
    {
        temp = head; // sätt
        
        if (pos < 1) // Om pos är mindre än 1.
        {
            temp= head;
            head = NewNode;
            head->next = temp;
            temp->prev = head;
            head->prev = NULL;
        }
        else
        {
            for (size_t i = 0; i < pos; i++) // letar sig fram till positionen.
            {
                if (temp->next != NULL)
                {
                    temp = temp->next; // sätt temp1 till temp1->next;
                }
                else
                {
                    break;
                }
            }
            
            NewNode->prev = temp->prev; 
            NewNode->next = temp;
            temp->prev = NewNode;
            NewNode->prev->next = NewNode;
            temp = NewNode->next;
            
            if (temp != NULL)
            {
                temp->prev = NewNode;
            }
            
        }
        if (tail->next != NULL)
            tail = tail->next;
        
    }
    else // Om Head är tomt och man vill sätta något på annan pos.
    {
        std::cerr << "Det finns inget på pos 0" << std:: endl;
        
    }
}
void linked_list::push_back(double value)
{
    if (!(head && tail)) { // om Head och tail inte finns så sätt värdet till head och tail
       node_t* tmp = new node_t(value);
        head = tail = tmp;
    }else
    {
        node_t* tmp = new node_t(value); // bygger på tail.
        tail->next = tmp;
        tmp->prev = tail;
        tail = tmp;
    }
}

void linked_list::push_front(double value)
{
    if(!(head && tail)){ // om Head och tail inte finns så sätt värdet till head och tail
        node_t* tmp = new node_t(value);
        head = tail = tmp;
    }else
    {
        node_t* tmp = new node_t(value); // bygger på head
        head->prev = tmp;
        tmp->next = head;
        head = tmp;
    }
    
}

// remove and access
double linked_list::pop_back()
{
    double value;
   node_t* tmp = tail->prev; // Skapar en temorär node som går till näst sista värdet.
    if(tmp)
    {
        tmp->next = nullptr; // tmp där next är nullptr
        value=tail->value; // value tar tailens värde
        delete tail; // deletar tail
        tail = tmp; // sätter tail till värdet som var på tmp
    }else
    {
        value = tail->value;
        delete tail;
        head = tail = nullptr; // sätter allt till nullptr
        
    }
    
    return value;
}

double linked_list::pop_front()
{
    double value;
    node_t* tmp = head->next; // Skapar en temporär node som går till värdet bakom head.
    if(tmp)
    {
        tmp->prev = nullptr; // tmp går dit prev är nullptr
        value = head->value; // value tar heads värde
        delete head; // deletar head
        head = tmp; // sätter head till värdet tmp har
    }else
    {
        value = head->value; // value tar heads värde
        delete head;
        head = tail = nullptr; // sätter allt till nullptr xD
    }
    return value;
}

// accessing elements
double linked_list::front() const
{
    
    if (head != NULL)
    {
        return head->value; // visar värdet på head
    }
    else
    {
        return NULL;
    }
    
}

double linked_list::back() const
{
    
    if (tail != NULL)
    {
        return tail->value; // vistar värdet på tail
    }
    else
    {
        return NULL;
    }
}

double linked_list::at(size_t pos) const
{
    node_t *iterator = head;
    for (size_t i = 0; i < pos; i++) { // Loppar antal gånger som efterfrågas
        iterator = iterator->next;
    }
    
    return iterator->value;
}

// removing elements

// Loopar fram till angivna positionen och kollar så den existerar, ifall den existerar ta bort den.
void linked_list::remove (size_t pos)
{
    node_t *iterator = head;
    node_t *tmp;
    
    if (head != NULL)
    {
        for (size_t i = 0; i < pos; i++)
        {
            iterator = iterator->next;
        }
        
        if (iterator->prev != NULL)
        {
            tmp = iterator->prev;
            tmp->next = iterator->next;
        }
        if (iterator->next != NULL)
        {
            tmp = iterator->next;
            tmp->prev = iterator->prev;
        }
        delete iterator;
        
        
    }
    
}

// informational

bool linked_list::is_empty() const
{
    return head == nullptr; // kollar om huvudet är en nullptr isåfall är den tom.
}

//en count som räknar varje steg till slutet av listan
size_t linked_list::size() const
{
    size_t count = 0;
    node_t* iterator = head;
    while(iterator)
    {
        iterator = iterator->next; // ta iterator till nästa värde
        ++count; // räkna antal gånger iterator finns.
    }
    return count;
}

// output
// Börjar från huvudet och skriver ut värdet framåt
void linked_list::print() const
{
    node_t* iterator = head;
    while (iterator) {
        std::cout << iterator->value << "\n"; // skriv ut value
        iterator = iterator->next; // iterator till nästa värde
    }
}
// Börjar från tail och skriver ut allt backifrån
void linked_list::print_reverse() const
{
    node_t* iterator = tail;
    while (iterator) {
        std::cout << iterator->value << "\n"; // skriv ut value
        iterator = iterator->prev; // iterator till föregående värde eftersom vi går bakvägen
    }
}

//Merge
// Länkar samma två listor
linked_list linked_list::merge(linked_list list1, linked_list list2)
{
    node_t *head1 = list1.head, *head2 = list2.head;
    linked_list tmp;

    
    while (head1 != NULL && head2 != NULL)
    {
        
        // Om värdet på head1 är lägre eller samma stoppa in värdet i tmp
        if(head1->value <= head2->value)
        {
            
            tmp.push_back(head1->value);
            head1 = head1->next;
            list1.pop_front();
            list1.front();
            
        }
        // Om värdet i head2 är lägre stoppa in värdet i tmp
        else if (head1->value > head2->value)
        {
        
            tmp.push_back(head2->value);
            head2 = head2->next;
            list2.pop_front();
            list2.front();
            
        }
        
    }
    //Så länge head2 har ett värdet stoppa in värdet i tmp
    while(head2 != NULL)
    {
        tmp.push_back(head2->value);
        head2 = head2->next;
        list2.pop_front();
        list2.front();
    }
    //Så länge head2 har ett värdet stoppa in värdet i tmp
    while(head1 != NULL)
    {
        tmp.push_back(head1->value);
        head1 = head1->next;
        list1.pop_front();
        list1.front();
    }
    //return tmp listan.
    return operator=(tmp);
}

//Check if sorted
bool linked_list::isSorted() const
{
    node_t *iterator = head;
    double tmp;
    
    if (!iterator) return true; // Empty list
    
   // Sparar värdet av nuvarande node
    tmp = iterator->value;
    
    // Pekar på nästa node
    iterator = iterator->next;
    
    while (iterator)
    {
        if(tmp > iterator->value)
        {
            std::cout << "Listan är inte sorterad " << std::endl;
            return false;
        }
        // Sparar värdet av nuvarande node
        tmp = iterator->value;
        
        // Pekar på nästa node
        iterator = iterator->next;
    }
    
    std::cout << "Listan är sorterad " << std::endl;
    return true;
    
}

