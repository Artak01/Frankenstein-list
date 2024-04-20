#include <iostream>
#include "frank_list.h"
namespace vhuk {
template <typename T>
FrankList<T>::Node::Node()
    : val {0}
    , next {nullptr}
    , prev {nullptr}
    , asc {nullptr}
    , desc {nullptr}
{}

template <typename T>
FrankList<T>::Node::Node(T val)
    : val {val}
    , next {nullptr}
    , prev {nullptr}
    , asc {nullptr}
    , desc {nullptr}
{}
/*
///base_iterator///
template <typename T>
FrankList<T>::base_iterator::~base_iterator()
{
    ptr = nullptr;
}

template <typename T>
bool FrankList<T>::base_iterator::operator== (const base_iterator& rhv) const
{ 
    return ptr == rhv.ptr;
}

template <typename T>
bool FrankList<T>::base_iterator::operator!= (const base_iterator& rhv) const
{
    return ptr != rhv.ptr;
}

template <typename T>
FrankList<T>::base_iterator::base_iterator(Node* ptr)
    : ptr {ptr}
{}

///const_iterator///
template <typename T>
FrankList<T>::const_iterator::const_iterator (const base_iterator& rhv)
    : base_iterator(rhv.ptr)
{}

template <typename T>
FrankList<T>::const_iterator::const_iterator (base_iterator&& rhv)
    : base_iterator(rhv.ptr)
{}
    
template <typename T>
const FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator= (const base_iterator& rhv)
{
    this -> ptr = rhv -> ptr;
    return *this;
}

template <typename T>
const FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator= (base_iterator&& rhv)
{
    this -> ptr = rhv -> ptr;
    rhv -> ptr = nullptr;
    return *this;
}


template <typename T>
FrankList<T>::const_reference FrankList<T>::const_iterator::operator* () const
{ 
    return this -> ptr -> val;
}

template <typename T>
FrankList<T>::const_pointer FrankList<T>::const_iterator::operator-> () const
{
    return &(this -> ptr -> val);
}

template <typename T>
const FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator++() 
{
    this -> ptr = this -> ptr -> next;
    return *this;
}

template <typename T>
const FrankList<T>::const_iterator FrankList<T>::const_iterator::operator++(value_type)
{
    const_iterator tmp = *this; 
    ++(*this);
    return tmp;
}

template <typename T>
const FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator--()
{
    this -> ptr = this -> ptr -> prev;
    return *this;
}

template <typename T>
const FrankList<T>::const_iterator FrankList<T>::const_iterator::operator--(value_type)
{
    const_iterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T>
FrankList<T>::const_iterator::const_iterator (Node* ptr)
    : base_iterator(ptr)
{}

///iterator///
template <typename T>
FrankList<T>::iterator::iterator(const base_iterator& rhv)
    : base_iterator (rhv.ptr)
{}

template <typename T>
FrankList<T>::iterator::iterator(base_iterator&& rhv)
    : base_iterator (rhv.ptr)
{}

template <typename T>
FrankList<T>::reference FrankList<T>::iterator::operator* ()
{
    return this -> ptr -> val;
}

template <typename T>
FrankList<T>::pointer FrankList<T>::iterator::operator-> ()
{
    return &(this -> ptr -> val);
}


template <typename T>
const FrankList<T>::iterator& FrankList<T>::iterator::operator= (const base_iterator& rhv)
{
    this -> ptr = rhv -> ptr;
    return *this;
}

template <typename T>
const FrankList<T>::iterator& FrankList<T>::iterator::operator= (base_iterator&& rhv)
{
    this -> ptr = rhv -> ptr;
    rhv -> ptr = nullptr;
    return *this;
}


template <typename T>
FrankList<T>::iterator::iterator (Node* ptr)
    : base_iterator(ptr)
{}

///const_reverse_iterator///

template <typename T>
FrankList<T>::const_reverse_iterator::const_reverse_iterator (const base_iterator& rhv)
    : base_iterator(rhv.ptr)
{}

template <typename T>
FrankList<T>::const_reverse_iterator::const_reverse_iterator (base_iterator&& rhv)
    : base_iterator(rhv.ptr)
{}


template <typename T>
const FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator= (const base_iterator& rhv)
{
    this -> ptr = rhv -> ptr;
    return *this;
}

template <typename T>
const FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator= (base_iterator&& rhv)
{
    this -> ptr = rhv -> ptr;
    rhv -> ptr = nullptr;
    return *this;
}


template <typename T>
FrankList<T>::const_reference FrankList<T>::const_reverse_iterator::operator* () const
{
    return this -> ptr -> val;
}

template <typename T>
FrankList<T>::const_pointer FrankList<T>::const_reverse_iterator::operator-> () const
{
    return &(this -> ptr -> val);
}

template <typename T>
const FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator++()
{

    this -> ptr = this -> ptr -> prev;
    return *this;
}

template <typename T>
const FrankList<T>::const_reverse_iterator FrankList<T>::const_reverse_iterator::operator++(value_type)
{
    const_reverse_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T>
const FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator--()
{
    this -> ptr = this -> ptr -> next;
    return *this;
}

template <typename T>
const FrankList<T>::const_reverse_iterator FrankList<T>::const_reverse_iterator::operator--(value_type)
{
    const_reverse_iterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T>
FrankList<T>::const_reverse_iterator::const_reverse_iterator (Node* ptr)
    : base_iterator(ptr)
{}

///reverse_iterator///
template <typename T>
FrankList<T>::reverse_iterator::reverse_iterator(const base_iterator& rhv)
    : base_iterator (rhv.ptr)
{}

template <typename T>
FrankList<T>::reverse_iterator::reverse_iterator(base_iterator&& rhv)
    : base_iterator (rhv.ptr)
{}

template <typename T>
FrankList<T>::reference FrankList<T>::reverse_iterator::operator* ()
{
    return this -> ptr -> val;
}

template <typename T>
FrankList<T>::pointer FrankList<T>::reverse_iterator::operator-> ()
{
    return &(this -> ptr -> val);
}


template <typename T>
const FrankList<T>::reverse_iterator& FrankList<T>::reverse_iterator::operator= (const base_iterator& rhv)
{
    this -> ptr = rhv -> ptr;
    return *this;
}

template <typename T>
const FrankList<T>::reverse_iterator& FrankList<T>::reverse_iterator::operator= (base_iterator&& rhv)
{
    this -> ptr = rhv -> ptr;
    rhv -> ptr = nullptr;
    return *this;
}


template <typename T>
FrankList<T>::reverse_iterator::reverse_iterator (Node* ptr)
    : base_iterator(ptr)
{}

///const_asc_iterator///
template <typename T>
FrankList<T>::const_asc_iterator::const_asc_iterator(const base_iterator& rhv)
    :base_iterator(rhv.ptr)
{}

template <typename T>
FrankList<T>::const_asc_iterator::const_asc_iterator(base_iterator&& rhv)
    :base_iterator(rhv.ptr)
{}


template <typename T>
const FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator= (const base_iterator& rhv)
{
    this -> ptr = rhv -> ptr;
    return *this;
}

template <typename T>
const FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator= (base_iterator&& rhv)
{
    this -> ptr = rhv -> ptr;
    rhv -> ptr = nullptr;
    return *this;
}


template <typename T>
FrankList<T>::const_reference FrankList<T>::const_asc_iterator::operator*() const {

    return this -> ptr -> val;
}

template <typename T> 
FrankList<T>::const_pointer FrankList<T>::const_asc_iterator::operator->() const
{

    return &(this-> ptr -> val);
}

template <typename T>
const FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator++()
{

    this -> ptr = this -> ptr -> asc;
    return *this;
}

template <typename T>
const FrankList<T>::const_asc_iterator FrankList<T>::const_asc_iterator::operator++(value_type)
{
    const_asc_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T>
const FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator--()
{
    this -> ptr = this -> ptr -> dasc;
    return *this;
}


template <typename T>
const FrankList<T>::const_asc_iterator FrankList<T>::const_asc_iterator::operator--(value_type)
{
    const_asc_iterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T>
FrankList<T>::const_asc_iterator::const_asc_iterator(Node* ptr)
    :base_iterator(ptr)
{}

///asc_iterator///
template <typename T>
FrankList<T>::asc_iterator::asc_iterator(const base_iterator& rhv)
    :base_iterator(rhv.ptr)
{}

template <typename T>
FrankList<T>::asc_iterator::asc_iterator(base_iterator&& rhv)
    :base_iterator(rhv.ptr)
{}

template <typename T>
FrankList<T>::reference FrankList<T>::asc_iterator::operator* ()
{
    return this -> ptr-> val;
}

template <typename T>
FrankList<T>::pointer FrankList<T>::asc_iterator::operator-> ()
{
    return &(this-> ptr -> val);
}


template <typename T>
const FrankList<T>::asc_iterator& FrankList<T>::asc_iterator::operator= (const base_iterator& rhv)
{
    this -> ptr = rhv -> ptr;
    return *this;
}

template <typename T>
const FrankList<T>::asc_iterator& FrankList<T>::asc_iterator::operator= (base_iterator&& rhv)
{
    this -> ptr = rhv -> ptr;
    rhv -> ptr = nullptr;
    return *this;
}


template <typename T>
FrankList<T>::asc_iterator::asc_iterator(Node* ptr)
    :base_iterator(ptr)
{}

///const_desc_iterator///
template <typename T>
FrankList<T>::const_desc_iterator::const_desc_iterator(const base_iterator& rhv)
    :base_iterator(rhv)
{}

template <typename T>
FrankList<T>::const_desc_iterator::const_desc_iterator(base_iterator&& rhv)
    :base_iterator(rhv.ptr)
{}


template <typename T>
const FrankList<T>::const_desc_iterator& FrankList<T>::const_desc_iterator::operator= (const base_iterator& rhv)
{
    this -> ptr = rhv -> ptr;
    return *this;
}

template <typename T>
const FrankList<T>::const_desc_iterator& FrankList<T>::const_desc_iterator::operator= (base_iterator&& rhv)
{
    this -> ptr = rhv -> ptr;
    rhv -> ptr = nullptr;
    return *this;
}


template <typename T>
FrankList<T>::const_reference FrankList<T>::const_desc_iterator::operator*() const 
{
    return this -> ptr -> val;
}

template <typename T>
FrankList<T>::const_pointer FrankList<T>::const_desc_iterator::operator->() const
{
    return &(this -> ptr -> val);
}


template <typename T>
const FrankList<T>::const_desc_iterator& FrankList<T>::const_desc_iterator::operator++()
{
    this -> ptr = this -> ptr -> dasc;
    return *this;
}

template <typename T>
const FrankList<T>::const_desc_iterator FrankList<T>::const_desc_iterator::operator++(value_type)
{
    const_desc_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T>
const FrankList<T>::const_desc_iterator& FrankList<T>::const_desc_iterator::operator--()
{
    this -> ptr = this -> ptr -> asc;
    return *this;
}

template <typename T>
const FrankList<T>::const_desc_iterator FrankList<T>::const_desc_iterator::operator--(value_type)
{
    const_desc_iterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T>
FrankList<T>::const_desc_iterator::const_desc_iterator(Node* ptr)
    :base_iterator(ptr)
{}

////desc_iterator///
template <typename T>
FrankList<T>::desc_iterator::desc_iterator(const base_iterator& rhv)
    :base_iterator(rhv.ptr)
{}

template <typename T>
FrankList<T>::desc_iterator::desc_iterator(base_iterator&& rhv)
    :base_iterator(rhv.ptr)
{}


template <typename T>
FrankList<T>::reference FrankList<T>::desc_iterator::operator*()
{
    return this -> ptr -> val;
}

template <typename T>
FrankList<T>::pointer FrankList<T>::desc_iterator::operator->()
{
    return &(this -> ptr -> val);
}


template <typename T>
const FrankList<T>::desc_iterator& FrankList<T>::desc_iterator::operator= (const base_iterator& rhv)
{
    this -> ptr = rhv -> ptr;
    return *this;
}

template <typename T>
const FrankList<T>::desc_iterator& FrankList<T>::desc_iterator::operator= (base_iterator&& rhv)
{
    this -> ptr = rhv -> ptr;
    rhv -> ptr = nullptr;
    return *this;
}


template <typename T>
FrankList<T>::desc_iterator::desc_iterator(Node* ptr)
    :base_iterator(ptr)
{}

*/
//FRANK_LIST///
template <typename T>
FrankList<T>::FrankList()
    : head {nullptr}
    , tail {nullptr}
    , ahead {nullptr}
    , atail {nullptr}
{}


template <typename T>
void FrankList<T>::push_front(const_reference elem)
{
    if(head == nullptr) {
        head = new Node(elem);
        tail = head;
        ahead = head;
        atail = head;
    } else {
        Node* tmp = new Node(elem);
        head -> prev = tmp;
        tmp -> next = head;
        head = tmp;
        put_in_sorted_order(tmp);
    }

}

template <typename T>
void FrankList<T>::push_back(const_reference elem)
{
    if(head == nullptr) {
        head = new Node(elem);
        tail = head;
        ahead = head;
        atail = head;
    } else {
        Node* tmp = new Node(elem);
        tmp -> prev = tail;
        tail -> next = tmp;
        tail = tmp;
        put_in_sorted_order(tmp);
    }
    
}

template <typename T>
void FrankList<T>::put_in_sorted_order (Node* ptr)
{
    if(ptr -> val <= ahead -> val)
    {
        ahead -> desc = ptr;
        ptr -> asc = ahead;
        ahead = ptr;
        return;
    }
    else if (ptr -> val >= atail -> val)
    {
        atail -> asc = ptr;
        ptr -> desc = atail;
        atail = ptr;
        return;
    }
    else 
    {
        Node* current = ahead;
        while (current -> val <= ptr -> val)
        {
            current  = current -> asc;
        }
        ptr -> asc = current;
        ptr -> desc = current -> desc;
        ptr -> desc -> asc = ptr;
        current -> desc = ptr;
    }
}

template <typename T>
typename FrankList<T>::size_type FrankList<T>::size() const
{
    if (!head){
        return 0;
    }
    size_type s = 0;
    Node* current = head;
    while(current != nullptr){
        current = current -> next;
        ++s;
    }
    return s;
}

template <typename T>
bool FrankList<T>::empty() const
{
    if (head){
        return false;
    }
    return true;
}
template <typename T>
void FrankList<T>::display() const
{
    Node* current = ahead;
    while(current){
        std::cout << current -> val << " ";
        current = current -> asc;
    }
    std::cout << std::endl;
}

template <typename T>
FrankList<T>::~FrankList(){}

}
