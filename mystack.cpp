//***************************************************************************
//
//  mystack.cpp
//  CSCI 241 Assignment 8
//
//  Created by Noah Allen (z1888906)
//
//***************************************************************************

#include "mystack.h"

//default constructor
mystack::mystack()
{
    stk_size = 0; // Number of items currently stored in the stack.
    stk_top = nullptr; // Stack top pointer. Pointer to the top (first) node in the linked list.
    //stackCapacity = 0;
    //stk = nullptr;
}

//copy constructor
mystack::mystack(const mystack& x)
{
    // Set the new stack object's list to empty
    stk_top = nullptr;
    
    // Copy the other stack's size
    stk_size = x.stk_size;

    // Copy the other stack's linked list
    clone(x);
}

//destructor
mystack::~mystack()
{
    delete[] stk;
}

//overloaded copy assignment operator
mystack& mystack::operator=(const mystack& x)
{
    if (this != &x)
    {
        delete[] stk;
        
        stackCapacity = x.stackCapacity;
        stk_size = x.stk_size;
        
        if (stackCapacity > 0)
        {
            stk = new char[stackCapacity];
        }
        else
        {
            stk = nullptr;
        }
        
        for (size_t i = 0; i < stk_size; i++)
        {
            stk[i] = x.stk[i];
        }
    }
    return *this;
}


/*//this function return the stack capacity
size_t mystack::capacity() const
{
    return stackCapacity;
}*/

//this function return the stack size
size_t mystack::size() const
{
    return stk_size;
}

//this function return true if the stack size is 0 Otherwise, return false.
bool mystack::empty() const
{
    if (stk_size == 0) return true;
    return false;
}

//this function set the stack size back to 0.
void mystack::clear()
{
    stk_size = 0;
}

/*//this function modifies an object's stack capacity
void mystack::reserve(size_t n)
{
    if (n < stk_size || n == stackCapacity)
        return;
    
    stackCapacity = n;
    char *tmp = new char[n];
    for (size_t i = 0; i < stk_size; i++)
    {
        tmp[i] = stk[i];
    }
    
    delete[] stk;
    stk = tmp;
}*/

//this function return the top item in the stack
const char& mystack::top() const
{
    return stk[stk_size - 1];
}

//this function push the character value onto the top of the stack
void mystack::push(char value)
{
    if (stk_size == stackCapacity)
    {
        if (stackCapacity == 0)
        {
            reserve(1);
        }
        else
        {
            reserve(stackCapacity * 2);
        }
    }
    stk[stk_size] = value;
    stk_size++;
}

//this function pop the top item off of the stack by decreasing the stack size by 1
void mystack::pop()
{
    stk_size--;
}

void clone(node *&x)
{
    last = nullptr;
    ptr = x.stk_top;

}