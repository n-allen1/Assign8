//***************************************************************************
//
//  mystack.cpp
//  CSCI 241 Assignment 8
//
//  Created by Noah Allen (z1888906)
//
//***************************************************************************
#include <iostream> 
#include <string> 
#include <cstdlib>
#include "mystack.h"

using namespace std;

//the copy constructor.initializes new stack object to the same.
mystack::mystack(const mystack& x)
{
	//top is set to nullptr. 
	stack_top = nullptr;
	
	//new stack size equals size of object x. 
	stack_size = x.stack_size;
	
	clone(x); 
		
}

mystack::~mystack()
{
	//destructor clears member function. 
	delete stack_top;//destructor can simply call the clear(). 

}

//overloaded copy assignment operator. 
mystack& mystack::operator=(const mystack& x)
{
	
	if (this != &x)
	{// Make the left stack object empty
		clear();
        
        // Copy the other stack's size
		stack_size = x.stack_size;

        // Copy the other stack's linked list
		clone(x);
    }
        
    return *this;
}

//returns size
size_t mystack::size()const
{

	return stack_size; 

}

//returns true if stack size is 0. 
bool mystack::empty() const
{

	return (stack_size == 0); 
}

//deletes nodes in stacks linked list, setting stack size to 0. 
void mystack::clear()
{
	while(!empty())
	{
		pop(); 
	}
}

//returns value in top node of stack. 
const int& mystack::top()const
{

	return stack_top-> value;

}

//pushes integer value onto top of the stack. 
void mystack::push(int value)
{
	//Allocate a new stack node, new_node
    node* new_node = new node(value, stack_top);
    
    stack_top = new_node;
    
    stack_size = stack_size + 1;

}

//pop the topp item off of the stack and deletes node. 
void mystack::pop()
{
    node* delete_node = stack_top;
    stack_top = stack_top->next;
    
    delete delete_node;
    
    stack_size = stack_size - 1;

}

void mystack::clone(const mystack& x)
{
	int value = 0; 

	node* last = nullptr; 
	node* ptr = x.stack_top; 
	
	while(ptr != nullptr)
	{
		node* new_node = new node (value, stack_top);
		new_node->value = ptr-> value;

		if(last == nullptr)
			stack_top = new_node;
		else
			last->next = new_node;

		last = new_node;
		ptr = ptr ->next;
	}
}