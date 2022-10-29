//***************************************************************************
//
//  inpost.cpp
//  CSCI 241 Assignment 8
//
//  Created by Noah Allen (z1888906)
//
//***************************************************************************
#include <iostream>
#include <string>
#include <cctype>
#include "mystack.h"
#include "inpost.h"


//includes definition.             //Same as assignment 8. 
std::string convert(const std::string& infix)
{
    std::string postfix;
    mystack s;
    int index = 0;

    while ( index < (int)infix.length())
    {
        if(islower(infix[index]))
        {
                postfix += infix[index];
                postfix += ' ';
                index++;
        }
	    else if(isdigit(infix[index]))
        {
 
            while(isdigit(infix[index]))
            {
                postfix += infix[index];
                index++;
            }
  
            postfix += ' ';
        }
        else if(infix[index] == ' ')
        {
            index++;
        }
        else if(infix[index] == '(')
        {
            s.push(infix[index]);
            index++;
        }
        else if(infix[index] == ')')
        {
  
            //this loop will check to make sure that the stack isn't empty
            //and that it is not a left parenthesis
            while(!s.empty() && s.top() != '(')
            {
                //will append the top character 
                //then proceed to pop the stack
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            
            if(!s.empty())
            {
                s.pop();
            }
            
            index++;
        }
        else
        {
            //thing is an operator
            while(!s.empty() && precedence(infix[index]) <= precedence(s.top()))
            {
                //gets top item and adds to postfix string
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }

            s.push(infix[index]);
            index++;
        }
    }
        //wrap up the loose ends
    while(!s.empty())
    {
        postfix += s.top();
        postfix += ' ';
        s.pop();
    }

    postfix.pop_back();
    
    return postfix;
 }

 int precedence(char op)
 {
 
         switch (op)
         {
                 case '~':
                 case '^':
                    return 3;
                    break;
                 case '*':
                 case '/':
                     return 2;
                     break;;
                 case '+':
                 case '-':
                     return 1;
                     break;
                 default:
                     return 0;
 
         }
 
 }