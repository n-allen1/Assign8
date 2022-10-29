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

#include <iostream>

struct node
{
	int value;
	node* next;

	node(int value, node* next = nullptr)
	{
		this-> value = value;
		this->next = next; 
	}
};

//Mystack Class
class mystack
{
	//private data
	private: 
		node* stack_top = nullptr;
		size_t stack_size = 0;
	
                void clone(const mystack&);
	//member fucntions. 
	public:
		mystack()= default; 
		mystack(const mystack& x);
		~mystack();
		mystack& operator= (const mystack& x);
		size_t size()const; 
		bool empty()const;
		void clear();
		const int& top()const;
		void push(int);
		void pop();

};
#endif