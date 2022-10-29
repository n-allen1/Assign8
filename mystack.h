//***************************************************************************
//
//  mystack.h
//  CSCI 241 Assignment 8
//
//  Created by Noah Allen (z1888906)
//
//***************************************************************************

#ifndef MYSTACK_H
#define MYSTACK_H

#include<cstdlib>

struct node
{
    int value;
    node* next;

    node(int value, node* next = nullptr)
    {
        this->value = value;
        this->next = next;
    }

};

class mystack
{
    private:
        //char *stk;
        //size_t stackCapacity;
        size_t stk_size;
        struct node *stk_top;
    
    
    public:
        mystack();
        mystack(const mystack& x);
        ~mystack();
        mystack& operator=(const mystack& x);
        //size_t capacity() const;
        size_t size() const;
        bool empty() const;
        void clear();
        //void reserve(size_t n);
        const int& top() const;
        void push(int value);
        void pop();
        void clone(node *&x);
};

#endif